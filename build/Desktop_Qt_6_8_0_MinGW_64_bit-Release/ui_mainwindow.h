/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *line;
    QLabel *label_5;
    QLabel *label_4;
    QComboBox *Game;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QComboBox *Game_Mode;
    QFrame *line_2;
    QPushButton *pushButton;
    QLineEdit *Player2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *Player1;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(910, 721);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #021a1a;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 22, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(110, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 50));
        frame->setStyleSheet(QString::fromUtf8("background-color: #00df83;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName("gridLayout");
        line = new QFrame(frame);
        line->setObjectName("line");
        line->setMinimumSize(QSize(0, 30));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("color: #021a1a;\n"
"font-size : 12pt;\n"
"font-weight: bold;\n"
""));

        gridLayout->addWidget(label_5, 8, 0, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color: #021a1a;\n"
"font-size : 12pt;\n"
"font-weight: bold;\n"
""));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        Game = new QComboBox(frame);
        Game->addItem(QString());
        Game->addItem(QString());
        Game->addItem(QString());
        Game->addItem(QString());
        Game->addItem(QString());
        Game->addItem(QString());
        Game->addItem(QString());
        Game->addItem(QString());
        Game->setObjectName("Game");
        Game->setMinimumSize(QSize(0, 60));
        QPalette palette;
        QBrush brush(QColor(238, 238, 238, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(2, 26, 26, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(238, 238, 238, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        Game->setPalette(palette);
        Game->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 15pt;\n"
"padding: 16px;"));

        gridLayout->addWidget(Game, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(125, 125));
        label_3->setScaledContents(true);

        horizontalLayout_2->addWidget(label_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(frame);
        label->setObjectName("label");
        QPalette palette1;
        QBrush brush3(QColor(0, 29, 61, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        QBrush brush4(QColor(0, 223, 131, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(0, 29, 61, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        label->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"Arial Rounded MT Bold\";\n"
"color: #021a1a;\n"
"margin: 16pt;"));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        Game_Mode = new QComboBox(frame);
        Game_Mode->addItem(QString());
        Game_Mode->addItem(QString());
        Game_Mode->addItem(QString());
        Game_Mode->setObjectName("Game_Mode");
        Game_Mode->setMinimumSize(QSize(0, 60));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        Game_Mode->setPalette(palette2);
        Game_Mode->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 15pt;\n"
"padding: 16px;"));

        gridLayout->addWidget(Game_Mode, 2, 0, 1, 1);

        line_2 = new QFrame(frame);
        line_2->setObjectName("line_2");
        line_2->setMinimumSize(QSize(0, 30));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_2, 10, 0, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 60));
        pushButton->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 15px;  \n"
"font-size : 16pt;\n"
"padding: 18px;\n"
"font-weight: bold;\n"
""));

        gridLayout->addWidget(pushButton, 11, 0, 1, 1);

        Player2 = new QLineEdit(frame);
        Player2->setObjectName("Player2");
        Player2->setMinimumSize(QSize(0, 40));
        Player2->setStyleSheet(QString::fromUtf8("color: #021a1a;\n"
"font-size : 15pt;"));

        gridLayout->addWidget(Player2, 9, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(100, 100));
        label_2->setMaximumSize(QSize(100, 100));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/VS_Photo.png")));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 1);

        Player1 = new QLineEdit(frame);
        Player1->setObjectName("Player1");
        Player1->setMinimumSize(QSize(0, 40));
        Player1->setStyleSheet(QString::fromUtf8("color: #021a1a;\n"
"font-size : 15pt;"));

        gridLayout->addWidget(Player1, 5, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 6, 0, 1, 1);


        gridLayout_2->addWidget(frame, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(109, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 22, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 910, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Player 2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Player 1", nullptr));
        Game->setItemText(0, QCoreApplication::translate("MainWindow", "Basic Tic Tac Toe", nullptr));
        Game->setItemText(1, QCoreApplication::translate("MainWindow", "Pyramic Tic-Tac-Toe", nullptr));
        Game->setItemText(2, QCoreApplication::translate("MainWindow", "5 x 5 Tic Tac Toe", nullptr));
        Game->setItemText(3, QCoreApplication::translate("MainWindow", "Word Tic-tac-toe", nullptr));
        Game->setItemText(4, QCoreApplication::translate("MainWindow", "Numerical Tic-Tac-Toe", nullptr));
        Game->setItemText(5, QCoreApplication::translate("MainWindow", "Inverse Tic Tac Toe", nullptr));
        Game->setItemText(6, QCoreApplication::translate("MainWindow", "4 x 4 Tic-Tac-Toe", nullptr));
        Game->setItemText(7, QCoreApplication::translate("MainWindow", "SUS Game", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "          HAVE FUN!          ", nullptr));
        Game_Mode->setItemText(0, QCoreApplication::translate("MainWindow", "Human Player", nullptr));
        Game_Mode->setItemText(1, QCoreApplication::translate("MainWindow", "Random Player", nullptr));
        Game_Mode->setItemText(2, QCoreApplication::translate("MainWindow", "AI Player", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        Player2->setText(QString());
        Player2->setPlaceholderText(QCoreApplication::translate("MainWindow", "enter name", nullptr));
        label_2->setText(QString());
        Player1->setText(QString());
        Player1->setPlaceholderText(QCoreApplication::translate("MainWindow", "enter name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
