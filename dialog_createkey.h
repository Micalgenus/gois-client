#ifndef DIALOG_CREATEKEY_H
#define DIALOG_CREATEKEY_H

#include <QMainWindow>
#include <QObject>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>

namespace Ui {
class dialog_createkey;
}

class dialog_createkey : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_createkey(QWidget *parent = 0);

    void set_admin(QString, QString, QNetworkAccessManager*, int*);

    ~dialog_createkey();

private slots:

    void finished(QNetworkReply *reply);
    void on_keycreate_createbtn_clicked();

    void on_keycreate_cancelbtn_clicked();

    void on_keycreate_sexman_clicked();

    void on_keycreate_sexwoman_clicked();



private:
    Ui::dialog_createkey *ui;
    QNetworkAccessManager *nam2;
    int* mod_check2;
    int setsex; //남자 = 1 , 여자 = 0
    QString admin_id;
    QString admin_pw;
    QString createkey_name;
    QString createkey_brith;
    QString createkey_sex;
};

#endif // DIALOG_CREATEKEY_H
