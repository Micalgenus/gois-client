#include "dialog_createkey.h"
#include "ui_dialog_createkey.h"

#include<QImage>
#include<QPixmap>
#include<QIcon>
#include<QMessageBox>
#include<QStandardItemModel>

dialog_createkey::dialog_createkey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_createkey)
{
    //nam2 = new QNetworkAccessManager(this);
    //connect(nam2,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished_create(QNetworkReply*)));

    ui->setupUi(this);
}

dialog_createkey::~dialog_createkey()
{
    delete ui;
}

void dialog_createkey::on_keycreate_createbtn_clicked()
{
    QString url = "http://api.gois.me/user/create";
    QByteArray post_data;

    createkey_name = ui->keycreate_nametext->text();
    createkey_brith = ui->keycreate_birthtext->text();
    if(this->setsex = 1) createkey_sex = "M";
    else createkey_sex = "F";


    qDebug() << admin_id <<" " <<admin_pw;
    qDebug() << createkey_name <<" " <<createkey_brith <<" "<< createkey_sex;

    post_data.append("admin_id=").append(this->admin_id).append("&").append("admin_pw=").append(this->admin_pw).append("&").append("name=").append(createkey_name).append("&").append("birth=").append(createkey_brith).append("&").append("sex=").append(createkey_sex);

    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    if(post_data.isEmpty()){
        nam2->get(request);
    }
    else{
        nam2->post(request,post_data);
    }
    *mod_check2 = 1;
    connect(nam2,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));

}

void dialog_createkey::finished(QNetworkReply *reply){
}


void dialog_createkey::set_admin(QString input_admin_id,QString input_admin_pw,QNetworkAccessManager* input_nam, int* input){

    admin_id = input_admin_id;
    admin_pw = input_admin_pw;
    nam2 = input_nam;
    mod_check2 = input;
}

void dialog_createkey::on_keycreate_cancelbtn_clicked()
{
    this->close();
}

void dialog_createkey::on_keycreate_sexman_clicked()
{
    setsex = 1;
}

void dialog_createkey::on_keycreate_sexwoman_clicked()
{
    setsex = 0;
}
