/********************************************************************************
** Form generated from reading UI file 'pyramic.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PYRAMIC_H
#define UI_PYRAMIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PYRAMIC
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *cell_02;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cell_11;
    QPushButton *cell_12;
    QPushButton *cell_13;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cell_20;
    QPushButton *cell_21;
    QPushButton *cell_22;
    QPushButton *cell_23;
    QPushButton *cell_24;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *Back;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *Clear;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line_4;
    QLabel *Player1_name;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Player2_name;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QFrame *line_3;
    QLabel *p1_score;
    QFrame *line_2;
    QLabel *p2_score;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PYRAMIC)
    {
        if (PYRAMIC->objectName().isEmpty())
            PYRAMIC->setObjectName("PYRAMIC");
        PYRAMIC->resize(800, 637);
        PYRAMIC->setStyleSheet(QString::fromUtf8("background-color: #021a1a;"));
        centralwidget = new QWidget(PYRAMIC);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("background-color: #00df83;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        cell_02 = new QPushButton(frame);
        cell_02->setObjectName("cell_02");
        cell_02->setMinimumSize(QSize(75, 75));
        cell_02->setMaximumSize(QSize(75, 75));
        cell_02->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_3->addWidget(cell_02);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        cell_11 = new QPushButton(frame);
        cell_11->setObjectName("cell_11");
        cell_11->setMinimumSize(QSize(75, 75));
        cell_11->setMaximumSize(QSize(75, 75));
        cell_11->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout->addWidget(cell_11);

        cell_12 = new QPushButton(frame);
        cell_12->setObjectName("cell_12");
        cell_12->setMinimumSize(QSize(75, 75));
        cell_12->setMaximumSize(QSize(75, 75));
        cell_12->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout->addWidget(cell_12);

        cell_13 = new QPushButton(frame);
        cell_13->setObjectName("cell_13");
        cell_13->setMinimumSize(QSize(75, 75));
        cell_13->setMaximumSize(QSize(75, 75));
        cell_13->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout->addWidget(cell_13);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        cell_20 = new QPushButton(frame);
        cell_20->setObjectName("cell_20");
        cell_20->setMinimumSize(QSize(75, 75));
        cell_20->setMaximumSize(QSize(75, 75));
        cell_20->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_2->addWidget(cell_20);

        cell_21 = new QPushButton(frame);
        cell_21->setObjectName("cell_21");
        cell_21->setMinimumSize(QSize(75, 75));
        cell_21->setMaximumSize(QSize(75, 75));
        cell_21->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_2->addWidget(cell_21);

        cell_22 = new QPushButton(frame);
        cell_22->setObjectName("cell_22");
        cell_22->setMinimumSize(QSize(75, 75));
        cell_22->setMaximumSize(QSize(75, 75));
        cell_22->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_2->addWidget(cell_22);

        cell_23 = new QPushButton(frame);
        cell_23->setObjectName("cell_23");
        cell_23->setMinimumSize(QSize(75, 75));
        cell_23->setMaximumSize(QSize(75, 75));
        cell_23->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_2->addWidget(cell_23);

        cell_24 = new QPushButton(frame);
        cell_24->setObjectName("cell_24");
        cell_24->setMinimumSize(QSize(75, 75));
        cell_24->setMaximumSize(QSize(75, 75));
        cell_24->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_2->addWidget(cell_24);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        Back = new QPushButton(frame);
        Back->setObjectName("Back");
        Back->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 15pt;\n"
"padding: 16px;"));

        horizontalLayout_8->addWidget(Back);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        QPalette palette;
        QBrush brush(QColor(2, 26, 26, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 223, 131, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(2, 26, 26, 128));
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
        label_4->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("font: 22pt \"Arial Rounded MT Bold\";\n"
"color: #021a1a;\n"
"margin: 16pt;"));

        horizontalLayout_8->addWidget(label_4);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        Clear = new QPushButton(frame);
        Clear->setObjectName("Clear");
        Clear->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 15pt;\n"
"padding: 16px;"));

        horizontalLayout_8->addWidget(Clear);


        gridLayout->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        line_4 = new QFrame(frame);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::Shape::VLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_4->addWidget(line_4);

        Player1_name = new QLabel(frame);
        Player1_name->setObjectName("Player1_name");
        Player1_name->setMinimumSize(QSize(150, 0));
        Player1_name->setMaximumSize(QSize(150, 16777215));
        Player1_name->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 16pt;\n"
"font-weight: bold;\n"
""));

        horizontalLayout_4->addWidget(Player1_name);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        line = new QFrame(frame);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_6->addWidget(line);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        Player2_name = new QLabel(frame);
        Player2_name->setObjectName("Player2_name");
        Player2_name->setMinimumSize(QSize(150, 0));
        Player2_name->setMaximumSize(QSize(150, 16777215));
        Player2_name->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 16pt;\n"
"font-weight: bold;\n"
""));

        horizontalLayout_5->addWidget(Player2_name);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setMinimumSize(QSize(163, 0));
        label->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 16pt;\n"
"font-weight: bold;\n"
""));

        horizontalLayout_7->addWidget(label);

        line_3 = new QFrame(frame);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_7->addWidget(line_3);

        p1_score = new QLabel(frame);
        p1_score->setObjectName("p1_score");
        p1_score->setMinimumSize(QSize(150, 0));
        p1_score->setMaximumSize(QSize(150, 16777215));
        p1_score->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 16pt;\n"
"font-weight: bold;\n"
""));

        horizontalLayout_7->addWidget(p1_score);

        line_2 = new QFrame(frame);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_7->addWidget(line_2);

        p2_score = new QLabel(frame);
        p2_score->setObjectName("p2_score");
        p2_score->setMinimumSize(QSize(150, 0));
        p2_score->setMaximumSize(QSize(150, 16777215));
        p2_score->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 16pt;\n"
"font-weight: bold;\n"
""));

        horizontalLayout_7->addWidget(p2_score);


        gridLayout_2->addLayout(horizontalLayout_7, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 4, 0, 1, 1);


        gridLayout_3->addWidget(frame, 1, 1, 3, 1);

        horizontalSpacer_8 = new QSpacerItem(60, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 3, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 91, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 4, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(59, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 2, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 0, 1, 1, 1);

        PYRAMIC->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PYRAMIC);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        PYRAMIC->setMenuBar(menubar);
        statusbar = new QStatusBar(PYRAMIC);
        statusbar->setObjectName("statusbar");
        PYRAMIC->setStatusBar(statusbar);

        retranslateUi(PYRAMIC);

        QMetaObject::connectSlotsByName(PYRAMIC);
    } // setupUi

    void retranslateUi(QMainWindow *PYRAMIC)
    {
        PYRAMIC->setWindowTitle(QCoreApplication::translate("PYRAMIC", "MainWindow", nullptr));
        cell_02->setText(QString());
        cell_11->setText(QString());
        cell_12->setText(QString());
        cell_13->setText(QString());
        cell_20->setText(QString());
        cell_21->setText(QString());
        cell_22->setText(QString());
        cell_23->setText(QString());
        cell_24->setText(QString());
        Back->setText(QCoreApplication::translate("PYRAMIC", "Back", nullptr));
        label_4->setText(QCoreApplication::translate("PYRAMIC", "Pyramic Tic-Tac-Toe", nullptr));
        Clear->setText(QCoreApplication::translate("PYRAMIC", "Clear", nullptr));
        Player1_name->setText(QCoreApplication::translate("PYRAMIC", "Player1", nullptr));
        Player2_name->setText(QCoreApplication::translate("PYRAMIC", "Player2", nullptr));
        label->setText(QCoreApplication::translate("PYRAMIC", "Score", nullptr));
        p1_score->setText(QCoreApplication::translate("PYRAMIC", "0", nullptr));
        p2_score->setText(QCoreApplication::translate("PYRAMIC", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PYRAMIC: public Ui_PYRAMIC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PYRAMIC_H
