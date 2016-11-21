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

#define PATH (QApplication::applicationDirPath() + "/../../")

namespace Ui {
class DB_project;
}

class DB_project : public QMainWindow
{
    Q_OBJECT

public:
    explicit DB_project(QWidget *parent = 0);
    ~DB_project();

private slots:
    //void on_login_btn_clicked();

private:
    Ui::DB_project *ui;
};

#endif // DB_PROJECT_H
