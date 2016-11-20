#include "db_project.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DB_project w;
    w.show();

    return a.exec();
}
