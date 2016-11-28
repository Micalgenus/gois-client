#include "db_project.h"
#include "ui_db_project.h"

#include<QImage>
#include<QPixmap>
#include<QIcon>
#include<QMessageBox>

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

    ui->s_login_group->hide();

    //login
    nam = new QNetworkAccessManager(this);
    connect(ui->login_btn,SIGNAL(clicked()),this,SLOT(on_login_btn_clicked()));
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));

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
    post_data.append("admin_id=").append(admin_id).append("&").append("admin_pw=").append(admin_pw);
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    if(post_data.isEmpty()){
        nam->get(request);
    }
    else{
        nam->post(request,post_data);
    }
}

void DB_project::finished(QNetworkReply *reply){
    QString check;
    if(reply->error() == QNetworkReply::NoError){
        check = QObject::tr(reply->readAll());
        if(check == "{\"status\":100}") {
            ui->login_group->hide();
            ui->s_login_group->show();
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


void DB_project::on_login_btn_5_clicked()
{
    ui->s_login_group->hide();
    ui->login_group->show();
}
