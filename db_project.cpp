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

    //button image set
    QPixmap Search_btn(PATH + "/img/search_icon.png");
    QIcon Search_icon(Search_btn);
    ui->search_btn->setIcon(Search_icon);

    QPixmap All_btn(PATH + "/img/all_icon.png");
    QIcon All_icon(All_btn);
    ui->all_btn->setIcon(All_icon);

    QPixmap Left_btn(PATH + "/img/left_icon.png");
    QIcon Left_icon(Left_btn);
    ui->left_btn->setIcon(Left_icon);

    QPixmap Right_btn(PATH + "/img/right_icon.png");
    QIcon Right_icon(Right_btn);
    ui->right_btn->setIcon(Right_icon);

    //start hide ui
    ui->s_login_group->hide();
    ui->search_txt->hide();
    ui->search_btn->hide();
    ui->all_btn->hide();
    ui->guest_table->hide();
    ui->inbody_info_2->hide();

    //login
    nam = new QNetworkAccessManager(this);
connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));
   //nam1 = new QNetworkAccessManager(this);
   //

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
            if(check == "{\"status\":100}") {
                ui->login_group->hide();
                ui->s_login_group->show();

                ui->guest_table->show();
                ui->search_txt->show();
                ui->search_btn->show();
                ui->all_btn->show();
                ui->inbody_info_2->show();
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

        QString tmp;
        QStringList list_id;
        QStringList list_name;
        QStringList list_gender;

        if(reply->error() == QNetworkReply::NoError){
            check = QObject::tr(reply->readAll());
            reply->deleteLater();
    qDebug() << check;
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
                }

                //Table View
                QStandardItemModel *model = new QStandardItemModel(ArraySize,3,this); //2 Rows and 3 Columns

                model->setHorizontalHeaderItem(0, new QStandardItem(QString("ID")));
                model->setHorizontalHeaderItem(1, new QStandardItem(QString("Name")));
                model->setHorizontalHeaderItem(2, new QStandardItem(QString("gender")));

                ui->guest_table->setModel(model);

                //row 값넣기
                for(int i = 0; i < ArraySize; i++) {
                    model->setItem(i,0,new QStandardItem(QString(list_id[i])));
                    model->setItem(i,1,new QStandardItem(QString(list_name[i])));
                    model->setItem(i,2,new QStandardItem(QString(list_gender[i])));
                }
            }
            else QMessageBox::information(this, "JsonList", "You don't load Json Data");
        }
        else{
            QMessageBox::information(this, "Error", reply->errorString());
        }
    }
}




//logout
void DB_project::on_login_btn_5_clicked()
{
    ui->s_login_group->hide();
    ui->login_group->show();
    ui->search_txt->hide();
    ui->search_btn->hide();
    ui->all_btn->hide();
    ui->guest_table->hide();
    ui->inbody_info_2->hide();
    ui->inbody_info_1->show();
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

    for(int i = 0 ; i < selected.size(); i++ )
    {
      //rowid = selected[i].row();
      rowid = selected[i].data();
      qDebug() << rowid.toString();
    }
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
