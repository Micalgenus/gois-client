#ifndef DB_PROJECT_H
#define DB_PROJECT_H

#include <QMainWindow>

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
    void on_login_btn_clicked();

private:
    Ui::DB_project *ui;
};

#endif // DB_PROJECT_H
