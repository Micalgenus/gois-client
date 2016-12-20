#ifndef INBODY_DIALOG_H
#define INBODY_DIALOG_H

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
class inbody_Dialog;
}

class inbody_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit inbody_Dialog(QWidget *parent = 0);
    void set_key(QString ,QString );
    void set_access(QString, QString, QNetworkAccessManager*, int*);
    ~inbody_Dialog();

private slots:
    void on_pushButton_clicked();
    void finished(QNetworkReply *reply);

    void on_pushButton_2_clicked();

private:
    Ui::inbody_Dialog *ui;
    QNetworkAccessManager *nam2;
    int* mod_check2;
    QString admin_id;
    QString admin_pw;
    QString createkey;
    QString agency;
};

#endif // INBODY_DIALOG_H
