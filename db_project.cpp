#include "db_project.h"
#include "ui_db_project.h"

#include<QImage>
#include<QPixmap>
#include<QIcon>
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

}

DB_project::~DB_project()
{
    delete ui;
}

void DB_project::on_login_btn_clicked()
{

}
