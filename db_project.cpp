#include "db_project.h"
#include "ui_db_project.h"

#include<QImage>
#include<QPixmap>
#include<QIcon>
#include<QMessageBox>
#include<QStandardItemModel>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>

DB_project::DB_project(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DB_project)
{
    ui->setupUi(this);

    //Label image set
    QPixmap pix(PATH + "/img/JJang1.jpg");
    int w = ui->inbody_img->width();
    int h = ui->inbody_img->height();
    ui->inbody_img->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix1(PATH + "/img/Inbody_info.png");
    int w1 = ui->inbody_img->width();
    int h1 = ui->inbody_img->height();
    ui->inbody_paper->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));


    //start hide ui
    ui->s_login_group->hide();
    ui->guest_table->hide();
    ui->inbody_info_2->hide();

    //login
    nam = new QNetworkAccessManager(this);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));
   //nam1 = new QNetworkAccessManager(this);


    //test
    /*
    ui->ID_label->setText("SM1092");
    ui->weight_progressBar->setValue(46);
    ui->s_muscle_progressBar->setValue(56);*/
    a_Key = "";

}

DB_project::~DB_project()
{
    delete ui;
}

void DB_project::on_login_btn_clicked()
{

    if(ui->login_btn->isEnabled()) ui->login_btn->setEnabled(false);

    QString url = "http://api.gois.me/admin/login";
    //QString paras = ui->pTextEdit_paras->toPlainText();
   // qDebug() << paras;
    QByteArray post_data;
    //post_data.append(paras);
    QString admin_id = ui->id_txt->text();
    QString admin_pw = ui->pw_txt->text();
    setadmin_pw = ui->pw_txt->text();
    post_data.append("admin_id=").append(admin_id).append("&").append("admin_pw=").append(admin_pw);
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    if(post_data.isEmpty()){
        nam->get(request);
    }
    else{
        nam->post(request,post_data);
    }

    mod_check = 0;


}

void DB_project::finished(QNetworkReply *reply){
    if(mod_check == 0){
        QString check;
        if(reply->error() == QNetworkReply::NoError){
            check = QObject::tr(reply->readAll());
            reply->deleteLater();

            qDebug()<<check;

            QJsonDocument jsonResponse = QJsonDocument::fromJson(check.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();
            a_Key = jsonObject["key"].toString();
            int jsonStatus = jsonObject["status"].toInt();

            if(jsonStatus == 100) {
                ui->login_group->hide();
                ui->s_login_group->show();

                ui->guest_table->show();
                ui->inbody_info_3->show();
                ui->inbody_info_1->hide();
                InfoSetTableView();    //login시 TableView보이기
            }
            else QMessageBox::information(this, "Login", "Your id or password not correct!");
        }
        else{
            //ui->textEdit_result->setPlainText(reply->errorString());
            ui->id_txt->setText(reply->errorString());
        }
        ui->pw_txt->clear();
        if(!ui->login_btn->isEnabled())
            ui->login_btn->setEnabled(true);
    }
    else if(mod_check == 1){//계정생성
        QString check;
        if(reply->error() == QNetworkReply::NoError){
            check = QObject::tr(reply->readAll());
            qDebug()<<check;

            QJsonDocument jsonResponse = QJsonDocument::fromJson(check.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();
            QString jsonKey = jsonObject["key"].toString();
            int jsonStatus = jsonObject["status"].toInt();
            if(jsonStatus == 100) {
              QMessageBox::information(this, "Key", "Your Key : "+ jsonKey);
              this_dialog->close();

              inbody_Dialog inbody_mamber;
              this_inbody = &inbody_mamber;
              inbody_mamber.set_key(jsonKey, this->a_Key);
              inbody_mamber.set_access(ui->id_txt->text(),setadmin_pw, nam, &mod_check);
              inbody_mamber.exec();
              inbody_mamber.show();

            }
            else QMessageBox::information(this, "Create", "Your User_Infor not correct!");
        }
        else{
            //ui->id_txt->setText(reply->errorString());
        }
        //ui->pw_txt->clear();
    }
    else if(mod_check == 2) {
        QString check;

        QStringList list_id;
        QStringList list_name;
        QStringList list_gender;
        QStringList list_birth;

        if(reply->error() == QNetworkReply::NoError){
            check = QObject::tr(reply->readAll());
            reply->deleteLater();

            QJsonDocument jsonResponse = QJsonDocument::fromJson(check.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();

            int ArrayStatus = jsonObject["status"].toInt();
            if(ArrayStatus == 100) {
                int ArraySize = jsonObject["size"].toInt();
                QJsonArray jsonArray = jsonObject["list"].toArray();


                foreach (const QJsonValue & value, jsonArray) {
                    QJsonObject obj = value.toObject();

                    list_id.append(obj["id"].toString());
                    list_name.append(obj["name"].toString());
                    list_gender.append(obj["sex"].toString());
                    list_birth.append(obj["birth"].toString());
                }

                //Table View
                QStandardItemModel *model = new QStandardItemModel(ArraySize,4,this); //2 Rows and 3 Columns

                model->setHorizontalHeaderItem(0, new QStandardItem(QString("ID")));
                model->setHorizontalHeaderItem(1, new QStandardItem(QString("Name")));
                model->setHorizontalHeaderItem(2, new QStandardItem(QString("gender")));
                model->setHorizontalHeaderItem(3, new QStandardItem(QString("birth")));

                ui->guest_table->setModel(model);

                //row 값넣기
                for(int i = 0; i < ArraySize; i++) {
                    model->setItem(i,0,new QStandardItem(QString(list_id[i])));
                    model->setItem(i,1,new QStandardItem(QString(list_name[i])));
                    model->setItem(i,2,new QStandardItem(QString(list_gender[i])));
                    model->setItem(i,3,new QStandardItem(QString(list_birth[i])));
                }
            }
            else QMessageBox::information(this, "JsonList", "You don't load Json Data");
        }
        else{
            QMessageBox::information(this, "Error", reply->errorString());
        }
    }
    else if(mod_check == 3) {
        QString check;

        QStringList list_key;
        QStringList list_date;

        if(reply->error() == QNetworkReply::NoError){
            check = QObject::tr(reply->readAll());
            reply->deleteLater();

            QJsonDocument jsonResponse = QJsonDocument::fromJson(check.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();

            int ArrayStatus = jsonObject["status"].toInt();
            if(ArrayStatus == 100) {
                int ArraySize = jsonObject["size"].toInt();
                QJsonArray jsonArray = jsonObject["list"].toArray();


                foreach (const QJsonValue & value, jsonArray) {
                    QJsonObject obj = value.toObject();

                    list_key.append(obj["key"].toString());
                    list_date.append(obj["date"].toString());
                }

                //Table View
                QStandardItemModel *model = new QStandardItemModel(ArraySize,2,this); //2 Rows and 3 Columns

                model->setHorizontalHeaderItem(0, new QStandardItem(QString("Key")));
                model->setHorizontalHeaderItem(1, new QStandardItem(QString("Date")));

                ui->inbody_info_list->setModel(model);

                //row 값넣기
                for(int i = 0; i < ArraySize; i++) {
                    model->setItem(i,0,new QStandardItem(QString(list_key[i])));
                    model->setItem(i,1,new QStandardItem(QString(list_date[i])));
                }
            }
            else QMessageBox::information(this, "JsonList", "You don't load Json Data");
        }
        else{
            QMessageBox::information(this, "Error", reply->errorString());
        }

    }
    else if(mod_check == 4){
        QString check;

        if(reply->error() == QNetworkReply::NoError){
            check = QObject::tr(reply->readAll());
            reply->deleteLater();

            qDebug() << check;

            QJsonDocument jsonResponse = QJsonDocument::fromJson(check.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();

            int ArrayStatus = jsonObject["status"].toInt();
            if(ArrayStatus == 100) {
                float wicell = jsonObject["wicell"].toString("F1").toFloat();
                float wocell = jsonObject["wocell"].toString().toFloat();
                float protein = jsonObject["protein"].toString().toFloat();
                float mineral = jsonObject["mineral"].toString().toFloat();
                float body_fat = jsonObject["body_fat"].toString().toFloat();
                float weight = jsonObject["weight"].toString().toFloat();
                float height = jsonObject["height"].toString().toFloat();
                float s_muscle = jsonObject["s_muscle"].toString().toFloat();
                float bmi = jsonObject["bmi"].toString().toFloat();
                float p_body_fat = jsonObject["p_body_fat"].toString().toFloat();
                float waist_hip = jsonObject["waist_hip"].toString().toFloat();

                //라벨 처리
                ui->HEIGHT_label->setText(jsonObject["height"].toString());
                ui->wicell_label->setText(jsonObject["wicell"].toString("F1"));
                ui->wocell_label->setText(jsonObject["wocell"].toString());
                ui->protein_label->setText(jsonObject["protein"].toString());
                ui->mineral_label->setText(jsonObject["mineral"].toString());
                ui->body_fat_label->setText(jsonObject["body_fat"].toString());
                ui->weight_label->setText(jsonObject["weight"].toString());
                //add
                ui->Wbody_label->setText(QString::number(wicell+wocell));
                ui->muscle_label->setText(QString::number(wicell+wocell+protein));
                ui->add_body_fat_label->setText(QString::number(wicell+wocell+protein+mineral));
                ui->add_body_fat_label->setText(QString::number(wicell+wocell+protein+mineral+body_fat));

                //process bar
                ui->weight_progressBar->setValue(weight);
                ui->s_muscle_progressBar->setValue(s_muscle);
                ui->body_fat_progressBar->setValue(body_fat);
                ui->bmi_progressBar->setValue(bmi);
                ui->p_body_fat_progressBar->setValue(p_body_fat);
                ui->waist_hip_progressBar->setValue(waist_hip);

                //Lean Balance
                ui->righta_progressBar->setValue(62);
                ui->lefta_progressBar->setValue(60);
                ui->body_progressBar->setValue(58);
                ui->rightf_progressBar->setValue(94);
                ui->leftf_progressBar->setValue(94);

                //qDebug() << test1;
                qDebug() << wicell;
                qDebug() << wocell;
                qDebug() << protein;
                qDebug() << mineral;
                qDebug() << body_fat;
                qDebug() << weight;
                qDebug() << s_muscle;
                qDebug() << "bmi : "<<bmi;
                qDebug() << p_body_fat;
                qDebug() << waist_hip;

            }
            else QMessageBox::information(this, "JsonList", "You don't load Json Data");
        }
        else{
            QMessageBox::information(this, "Error", reply->errorString());
        }

    }
    else if(mod_check == 5){//인바디정보 생
        QString check;
        if(reply->error() == QNetworkReply::NoError){
            check = QObject::tr(reply->readAll());
            qDebug()<<check;

            QJsonDocument jsonResponse = QJsonDocument::fromJson(check.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();
            int jsonStatus = jsonObject["status"].toInt();
            if(jsonStatus == 100) {
              QMessageBox::information(this, "Create", "Create sucess");
              this_inbody->close();
              InfoSetTableView();
            }
            else QMessageBox::information(this, "Create", "Your User_Infor not correct!");
        }
        else{
            //ui->id_txt->setText(reply->errorString());
        }
        //ui->pw_txt->clear();
    }
    else if(mod_check == 6){//인바디 점수 등록
        QString check;
        if(reply->error() == QNetworkReply::NoError){
            check = QObject::tr(reply->readAll());
            qDebug()<<check;

            QJsonDocument jsonResponse = QJsonDocument::fromJson(check.toUtf8());
            QJsonObject jsonObject = jsonResponse.object();
            int jsonStatus = jsonObject["status"].toInt();
            if(jsonStatus == 100) {
              QMessageBox::information(this, "Create", "Create sucess");
              this_inbody->close();
              InfoSetTableView();
            }
            else QMessageBox::information(this, "Create", "Your User_Infor not correct!");
        }
        else{
            //ui->id_txt->setText(reply->errorString());
        }
        //ui->pw_txt->clear();
    }
}


//logout
void DB_project::on_login_btn_5_clicked()
{
    ui->s_login_group->hide();
    ui->login_group->show();
    ui->guest_table->hide();
    ui->inbody_info_2->hide();
    ui->inbody_info_1->show();
    ui->inbody_info_3->hide();
}

void DB_project::InfoSetTableView() {

    QString url = "http://api.gois.me/admin/list";

    QByteArray post_data;

    QString admin_id = ui->id_txt->text();

    post_data.append("admin_id=").append(admin_id);
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    if(post_data.isEmpty()){
        nam->get(request);
    }
    else{
        nam->post(request,post_data);
    }
    mod_check = 2;
}


//Table View Make
void DB_project::MakeTableView(QNetworkReply *reply) {

}

//Table View Select
void DB_project::on_guest_table_clicked(const QModelIndex &index)
{
    QVariant rowid;

    QItemSelectionModel *selections = ui->guest_table->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();

//    for(int i = 0 ; i < selected.size(); i++ )
//    {
//      //rowid = selected[i].row();
//      rowid = selected[i].data();
//      qDebug() << rowid.toString();
//    }
    rowid = selected[0].data();
    QString member_id = rowid.toString();

    QString admin_id = ui->id_txt->text();

    birth = selected[3].data().toString();

    //인바디지에 id,이름,성별,나이. 출력
    ui->ID_label->setText(member_id);
    ui->GENDER_label->setText(selected[2].data().toString());
    ui->AGE_label->setText("23");



    qDebug() << member_id;
    //통신
    QString url = "http://api.gois.me/info/select";

    QByteArray post_data;
    post_data.append("admin_id=").append(admin_id).append("&").append("admin_pw=").append(setadmin_pw).append("&");
    post_data.append("id=").append(member_id);
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    if(post_data.isEmpty()){
        nam->get(request);
    }
    else{
        nam->post(request,post_data);
    }

    ui->inbody_info_2->hide();
    ui->inbody_info_3->show();
    mod_check = 3;
}

//member add btn
void DB_project::on_add_member_btn_clicked()
{
    //member 창 생성
    dialog_createkey member(this);
    this_dialog = &member;
    member.set_admin(ui->id_txt->text(),setadmin_pw, nam, &mod_check);
    member.exec();
    member.show();
}

//member inbody list click
void DB_project::on_inbody_info_list_clicked(const QModelIndex &index)
{
    QVariant rowid;

    QItemSelectionModel *selections = ui->inbody_info_list->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();

    rowid = selected[0].data();
    QString key = rowid.toString();

    QString admin_id = ui->id_txt->text();

    //datelabel 추가
    ui->date_time_label->setText(selected[1].data().toString());
    //qDebug()<<"생일 ; "<<birth;
    //qDebug()<<"sdfsd : "<<birth[0];
    //qDebug()<<"date : "<<selected[1].data().toString();
    ui->AGE_label->setText(birth);

    //통신
    QString url = "http://api.gois.me/info/detail";

    QByteArray post_data;
    post_data.append("admin_id=").append(admin_id).append("&").append("admin_pw=").append(setadmin_pw).append("&");
    post_data.append("key=").append(key);
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    if(post_data.isEmpty()){
        nam->get(request);
    }
    else{
        nam->post(request,post_data);
    }

    ui->inbody_info_2->show();
    ui->inbody_info_3->hide();
    mod_check = 4;

}

void DB_project::on_Re_pushButton_clicked()
{
    InfoSetTableView();//목록 재생성
}
