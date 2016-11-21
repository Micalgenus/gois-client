/********************************************************************************
** Form generated from reading UI file 'db_project.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DB_PROJECT_H
#define UI_DB_PROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DB_project
{
public:
    QWidget *centralWidget;
    QGroupBox *login_group;
    QLabel *id_lab;
    QLabel *pw_lab;
    QTextEdit *id_txt;
    QTextEdit *pw_txt;
    QPushButton *login_btn;
    QGroupBox *inbody_info_1;
    QLabel *inbody_img;
    QGroupBox *guest_list;
    QTableView *guest_table;
    QTextEdit *search_txt;
    QPushButton *search_btn;
    QPushButton *all_btn;
    QPushButton *left_btn;
    QPushButton *right_btn;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DB_project)
    {
        if (DB_project->objectName().isEmpty())
            DB_project->setObjectName(QStringLiteral("DB_project"));
        DB_project->resize(1024, 940);
        DB_project->setMinimumSize(QSize(1024, 940));
        DB_project->setMaximumSize(QSize(1024, 940));
        DB_project->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(DB_project);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        login_group = new QGroupBox(centralWidget);
        login_group->setObjectName(QStringLiteral("login_group"));
        login_group->setGeometry(QRect(20, 130, 241, 131));
        id_lab = new QLabel(login_group);
        id_lab->setObjectName(QStringLiteral("id_lab"));
        id_lab->setGeometry(QRect(50, 32, 21, 16));
        QFont font;
        font.setFamily(QStringLiteral("Blippo Blk BT"));
        font.setPointSize(12);
        id_lab->setFont(font);
        pw_lab = new QLabel(login_group);
        pw_lab->setObjectName(QStringLiteral("pw_lab"));
        pw_lab->setGeometry(QRect(50, 66, 21, 16));
        pw_lab->setFont(font);
        id_txt = new QTextEdit(login_group);
        id_txt->setObjectName(QStringLiteral("id_txt"));
        id_txt->setGeometry(QRect(90, 27, 101, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\353\202\230\353\210\224\353\260\224\353\245\270\352\263\240\353\224\225"));
        id_txt->setFont(font1);
        id_txt->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        id_txt->setInputMethodHints(Qt::ImhNone);
        id_txt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        id_txt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        id_txt->setTabChangesFocus(true);
        id_txt->setLineWrapMode(QTextEdit::NoWrap);
        pw_txt = new QTextEdit(login_group);
        pw_txt->setObjectName(QStringLiteral("pw_txt"));
        pw_txt->setGeometry(QRect(90, 61, 101, 24));
        pw_txt->setFont(font1);
        pw_txt->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        pw_txt->setInputMethodHints(Qt::ImhNone);
        pw_txt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pw_txt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pw_txt->setTabChangesFocus(true);
        pw_txt->setLineWrapMode(QTextEdit::NoWrap);
        login_btn = new QPushButton(login_group);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setGeometry(QRect(80, 100, 81, 23));
        login_btn->setFont(font);
        login_btn->setCursor(QCursor(Qt::PointingHandCursor));
        inbody_info_1 = new QGroupBox(centralWidget);
        inbody_info_1->setObjectName(QStringLiteral("inbody_info_1"));
        inbody_info_1->setGeometry(QRect(280, 130, 721, 761));
        inbody_img = new QLabel(inbody_info_1);
        inbody_img->setObjectName(QStringLiteral("inbody_img"));
        inbody_img->setGeometry(QRect(10, 13, 701, 741));
        inbody_img->setAutoFillBackground(false);
        inbody_img->setStyleSheet(QStringLiteral(""));
        guest_list = new QGroupBox(centralWidget);
        guest_list->setObjectName(QStringLiteral("guest_list"));
        guest_list->setGeometry(QRect(20, 306, 241, 585));
        guest_table = new QTableView(guest_list);
        guest_table->setObjectName(QStringLiteral("guest_table"));
        guest_table->setGeometry(QRect(10, 10, 221, 531));
        search_txt = new QTextEdit(guest_list);
        search_txt->setObjectName(QStringLiteral("search_txt"));
        search_txt->setGeometry(QRect(70, 547, 101, 25));
        search_txt->setFont(font1);
        search_txt->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        search_txt->setInputMethodHints(Qt::ImhNone);
        search_txt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        search_txt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        search_txt->setTabChangesFocus(true);
        search_txt->setLineWrapMode(QTextEdit::NoWrap);
        search_btn = new QPushButton(guest_list);
        search_btn->setObjectName(QStringLiteral("search_btn"));
        search_btn->setGeometry(QRect(176, 547, 25, 25));
        search_btn->setCursor(QCursor(Qt::PointingHandCursor));
        search_btn->setStyleSheet(QStringLiteral(""));
        all_btn = new QPushButton(guest_list);
        all_btn->setObjectName(QStringLiteral("all_btn"));
        all_btn->setGeometry(QRect(205, 547, 25, 25));
        all_btn->setCursor(QCursor(Qt::PointingHandCursor));
        all_btn->setStyleSheet(QStringLiteral(""));
        left_btn = new QPushButton(centralWidget);
        left_btn->setObjectName(QStringLiteral("left_btn"));
        left_btn->setGeometry(QRect(943, 105, 25, 21));
        left_btn->setCursor(QCursor(Qt::PointingHandCursor));
        left_btn->setAutoFillBackground(false);
        left_btn->setStyleSheet(QStringLiteral("background:url(:/Resource/img/left_icon.png)"));
        right_btn = new QPushButton(centralWidget);
        right_btn->setObjectName(QStringLiteral("right_btn"));
        right_btn->setGeometry(QRect(976, 105, 25, 21));
        right_btn->setCursor(QCursor(Qt::PointingHandCursor));
        right_btn->setStyleSheet(QStringLiteral("background:url(:/Resource/img/right_icon.png)"));
        DB_project->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DB_project);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        DB_project->setMenuBar(menuBar);
        statusBar = new QStatusBar(DB_project);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DB_project->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());

        retranslateUi(DB_project);

        QMetaObject::connectSlotsByName(DB_project);
    } // setupUi

    void retranslateUi(QMainWindow *DB_project)
    {
        DB_project->setWindowTitle(QApplication::translate("DB_project", "DB_project", 0));
        login_group->setTitle(QString());
        id_lab->setText(QApplication::translate("DB_project", "ID", 0));
        pw_lab->setText(QApplication::translate("DB_project", "PW", 0));
        login_btn->setText(QApplication::translate("DB_project", "Login", 0));
        inbody_info_1->setTitle(QString());
        inbody_img->setText(QString());
        guest_list->setTitle(QString());
        search_btn->setText(QString());
        all_btn->setText(QString());
        left_btn->setText(QString());
        right_btn->setText(QString());
        menu->setTitle(QApplication::translate("DB_project", "\355\214\214\354\235\274", 0));
        menu_2->setTitle(QApplication::translate("DB_project", "\354\240\225\353\263\264", 0));
    } // retranslateUi

};

namespace Ui {
    class DB_project: public Ui_DB_project {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_PROJECT_H
