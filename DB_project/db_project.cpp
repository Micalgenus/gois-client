#include "db_project.h"
#include "ui_db_project.h"

DB_project::DB_project(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DB_project)
{
    ui->setupUi(this);
}

DB_project::~DB_project()
{
    delete ui;
}
