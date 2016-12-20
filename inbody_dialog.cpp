#include "inbody_dialog.h"
#include "ui_inbody_dialog.h"
#include "db_project.h"

inbody_Dialog::inbody_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inbody_Dialog)
{
    ui->setupUi(this);
}

inbody_Dialog::~inbody_Dialog()
{
    delete ui;
}

//인바디 정보 입
void inbody_Dialog::on_pushButton_clicked()
{

    QString id = ui->user_id->text();
    //QString mdate;
    QString wicell = ui->user_id_2->text();
    QString wocell = ui->user_id_3->text();
    QString protein = ui->user_id_4->text();
    QString mineral = ui->user_id_5->text();
    QString body_fat = ui->user_id_6->text();
    QString weight = ui->user_id_7->text();
    QString height = ui->user_id_8->text();
    QString s_muscle = ui->user_id_9->text();
    QString bmi = ui->user_id_10->text();
    QString p_body_fat = ui->user_id_11->text();
    QString waist_hip = ui->user_id_12->text();
    QString point = ui->inbody_lineEdit->text();

    qDebug()<<"dfsdfsdfsdfsdf :"<<createkey;
    qDebug()<<"dfsdfsdfsdfsdf :"<<agency;

    //data 보내기
    QString url = "http://api.gois.me/info/insert";
    QByteArray post_data;

    post_data.append("admin_id=").append(this->admin_id).append("&").append("admin_pw=").append(this->admin_pw)
            .append("&").append("agency=").append(agency).append("&").append("id=").append(id)
            .append("&").append("key=").append(createkey).append("&").append("wicell=").append(wicell)
            .append("&").append("wocell=").append(wocell).append("&").append("protein=").append(protein)
            .append("&").append("mineral=").append(mineral).append("&").append("body_fat=").append(body_fat)
            .append("&").append("weight=").append(weight).append("&").append("height=").append(height)
            .append("&").append("s_muscle=").append(s_muscle).append("&").append("bmi=").append(bmi)
            .append("&").append("p_body_fat=").append(p_body_fat).append("&").append("waist_hip=").append(waist_hip)
            ;

    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    if(post_data.isEmpty()){
        nam2->get(request);
    }
    else{
        nam2->post(request,post_data);
    }
    *mod_check2 = 5;
    connect(nam2,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));


    //인바디 점수 등록
    url = "http://api.gois.me/info/point";
    post_data;

    post_data.append("admin_id=").append(this->admin_id).append("&").append("admin_pw=").append(this->admin_pw)
            .append("&").append("id=").append(id).append("&").append("point=").append(point)
            .append("&").append("key=").append(createkey);

    request = QNetworkRequest(QUrl(url));
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    if(post_data.isEmpty()){
        nam2->get(request);
    }
    else{
        nam2->post(request,post_data);
    }
    *mod_check2 = 6;
    connect(nam2,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));

}

void inbody_Dialog::finished(QNetworkReply *reply){
}



void inbody_Dialog::set_key(QString inputkey, QString inputagency){
    createkey = inputkey;
    agency = inputagency;
}

void inbody_Dialog::set_access(QString input_admin_id,QString input_admin_pw,QNetworkAccessManager* input_nam, int* input){
    admin_id = input_admin_id;
    admin_pw = input_admin_pw;
    nam2 = input_nam;
    mod_check2 = input;
}

void inbody_Dialog::on_pushButton_2_clicked()
{
    this->close();
}
