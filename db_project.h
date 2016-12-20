#ifndef DB_PROJECT_H
#define DB_PROJECT_H

#include <QMainWindow>
#include <QObject>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include "dialog_createkey.h"
#include "inbody_dialog.h"

#define PATH (QApplication::applicationDirPath() + "/../../")

namespace Ui {
class DB_project;
}

class DB_project : public QMainWindow
{
    Q_OBJECT

public:
    explicit DB_project(QWidget *parent = 0);
    int mod_check;
    QString a_Key;
    ~DB_project();

private slots:
    void on_login_btn_clicked();
    void finished(QNetworkReply *reply);

    void on_login_btn_5_clicked();

    void on_guest_table_clicked(const QModelIndex &index);

    void on_add_member_btn_clicked();

    //self made
    void MakeTableView(QNetworkReply *reply);
    void InfoSetTableView();


    void on_inbody_info_list_clicked(const QModelIndex &index);

    void on_Re_pushButton_clicked();

private:
    Ui::DB_project *ui;
    QNetworkAccessManager *nam;
    QString setadmin_pw;
    QString birth;
    dialog_createkey* this_dialog;
    inbody_Dialog* this_inbody;

};

#endif // DB_PROJECT_H
