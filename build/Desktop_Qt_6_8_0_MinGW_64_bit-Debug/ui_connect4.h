/********************************************************************************
** Form generated from reading UI file 'connect4.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT4_H
#define UI_CONNECT4_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connect4
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *c20;
    QPushButton *c21;
    QPushButton *c22;
    QPushButton *c23;
    QPushButton *c24;
    QPushButton *c25;
    QPushButton *c26;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *c00;
    QPushButton *c01;
    QPushButton *c02;
    QPushButton *c03;
    QPushButton *c04;
    QPushButton *c05;
    QPushButton *c06;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *c40;
    QPushButton *c41;
    QPushButton *c42;
    QPushButton *c43;
    QPushButton *c44;
    QPushButton *c45;
    QPushButton *c46;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer;
    QPushButton *col_0;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *col_1;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *col_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *col_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *col_4;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *col_5;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *col_6;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *Back;
    QLabel *label_4;
    QPushButton *Clear;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *Player1_name;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Player2_name;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QFrame *line_3;
    QLabel *label_2;
    QFrame *line_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *c30;
    QPushButton *c31;
    QPushButton *c32;
    QPushButton *c33;
    QPushButton *c34;
    QPushButton *c35;
    QPushButton *c36;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *c10;
    QPushButton *c11;
    QPushButton *c12;
    QPushButton *c13;
    QPushButton *c14;
    QPushButton *c15;
    QPushButton *c16;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *c50;
    QPushButton *c51;
    QPushButton *c52;
    QPushButton *c53;
    QPushButton *c54;
    QPushButton *c55;
    QPushButton *c56;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Connect4)
    {
        if (Connect4->objectName().isEmpty())
            Connect4->setObjectName("Connect4");
        Connect4->resize(1030, 833);
        Connect4->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);"));
        centralwidget = new QWidget(Connect4);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 62, 70);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        c20 = new QPushButton(frame);
        c20->setObjectName("c20");
        c20->setEnabled(false);
        c20->setMinimumSize(QSize(75, 75));
        c20->setMouseTracking(false);
        c20->setTabletTracking(false);
        c20->setCheckable(true);

        horizontalLayout_10->addWidget(c20);

        c21 = new QPushButton(frame);
        c21->setObjectName("c21");
        c21->setEnabled(false);
        c21->setMinimumSize(QSize(75, 75));

        horizontalLayout_10->addWidget(c21);

        c22 = new QPushButton(frame);
        c22->setObjectName("c22");
        c22->setEnabled(false);
        c22->setMinimumSize(QSize(75, 75));

        horizontalLayout_10->addWidget(c22);

        c23 = new QPushButton(frame);
        c23->setObjectName("c23");
        c23->setEnabled(false);
        c23->setMinimumSize(QSize(75, 75));

        horizontalLayout_10->addWidget(c23);

        c24 = new QPushButton(frame);
        c24->setObjectName("c24");
        c24->setEnabled(false);
        c24->setMinimumSize(QSize(75, 75));

        horizontalLayout_10->addWidget(c24);

        c25 = new QPushButton(frame);
        c25->setObjectName("c25");
        c25->setEnabled(false);
        c25->setMinimumSize(QSize(75, 75));

        horizontalLayout_10->addWidget(c25);

        c26 = new QPushButton(frame);
        c26->setObjectName("c26");
        c26->setEnabled(false);
        c26->setMinimumSize(QSize(75, 75));

        horizontalLayout_10->addWidget(c26);


        gridLayout->addLayout(horizontalLayout_10, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        c00 = new QPushButton(frame);
        c00->setObjectName("c00");
        c00->setEnabled(false);
        c00->setMinimumSize(QSize(75, 75));
        c00->setMouseTracking(false);
        c00->setTabletTracking(false);
        c00->setCheckable(true);

        horizontalLayout_3->addWidget(c00);

        c01 = new QPushButton(frame);
        c01->setObjectName("c01");
        c01->setEnabled(false);
        c01->setMinimumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(c01);

        c02 = new QPushButton(frame);
        c02->setObjectName("c02");
        c02->setEnabled(false);
        c02->setMinimumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(c02);

        c03 = new QPushButton(frame);
        c03->setObjectName("c03");
        c03->setEnabled(false);
        c03->setMinimumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(c03);

        c04 = new QPushButton(frame);
        c04->setObjectName("c04");
        c04->setEnabled(false);
        c04->setMinimumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(c04);

        c05 = new QPushButton(frame);
        c05->setObjectName("c05");
        c05->setEnabled(false);
        c05->setMinimumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(c05);

        c06 = new QPushButton(frame);
        c06->setObjectName("c06");
        c06->setEnabled(false);
        c06->setMinimumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(c06);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        c40 = new QPushButton(frame);
        c40->setObjectName("c40");
        c40->setEnabled(false);
        c40->setMinimumSize(QSize(75, 75));
        c40->setMouseTracking(false);
        c40->setTabletTracking(false);
        c40->setCheckable(true);

        horizontalLayout_12->addWidget(c40);

        c41 = new QPushButton(frame);
        c41->setObjectName("c41");
        c41->setEnabled(false);
        c41->setMinimumSize(QSize(75, 75));

        horizontalLayout_12->addWidget(c41);

        c42 = new QPushButton(frame);
        c42->setObjectName("c42");
        c42->setEnabled(false);
        c42->setMinimumSize(QSize(75, 75));

        horizontalLayout_12->addWidget(c42);

        c43 = new QPushButton(frame);
        c43->setObjectName("c43");
        c43->setEnabled(false);
        c43->setMinimumSize(QSize(75, 75));

        horizontalLayout_12->addWidget(c43);

        c44 = new QPushButton(frame);
        c44->setObjectName("c44");
        c44->setEnabled(false);
        c44->setMinimumSize(QSize(75, 75));

        horizontalLayout_12->addWidget(c44);

        c45 = new QPushButton(frame);
        c45->setObjectName("c45");
        c45->setEnabled(false);
        c45->setMinimumSize(QSize(75, 75));

        horizontalLayout_12->addWidget(c45);

        c46 = new QPushButton(frame);
        c46->setObjectName("c46");
        c46->setEnabled(false);
        c46->setMinimumSize(QSize(75, 75));

        horizontalLayout_12->addWidget(c46);


        gridLayout->addLayout(horizontalLayout_12, 7, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);

        col_0 = new QPushButton(frame);
        col_0->setObjectName("col_0");
        col_0->setMinimumSize(QSize(50, 50));
        col_0->setMaximumSize(QSize(50, 50));
        col_0->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));

        horizontalLayout_13->addWidget(col_0);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);

        col_1 = new QPushButton(frame);
        col_1->setObjectName("col_1");
        col_1->setMinimumSize(QSize(50, 50));
        col_1->setMaximumSize(QSize(50, 50));
        col_1->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));

        horizontalLayout_13->addWidget(col_1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_3);

        col_2 = new QPushButton(frame);
        col_2->setObjectName("col_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(col_2->sizePolicy().hasHeightForWidth());
        col_2->setSizePolicy(sizePolicy);
        col_2->setMinimumSize(QSize(50, 50));
        col_2->setMaximumSize(QSize(50, 50));
        col_2->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));

        horizontalLayout_13->addWidget(col_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_4);

        col_3 = new QPushButton(frame);
        col_3->setObjectName("col_3");
        col_3->setMinimumSize(QSize(50, 50));
        col_3->setMaximumSize(QSize(50, 50));
        col_3->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));

        horizontalLayout_13->addWidget(col_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

        col_4 = new QPushButton(frame);
        col_4->setObjectName("col_4");
        col_4->setMinimumSize(QSize(50, 50));
        col_4->setMaximumSize(QSize(50, 50));
        col_4->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));

        horizontalLayout_13->addWidget(col_4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);

        col_5 = new QPushButton(frame);
        col_5->setObjectName("col_5");
        col_5->setMinimumSize(QSize(50, 50));
        col_5->setMaximumSize(QSize(50, 50));
        col_5->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));

        horizontalLayout_13->addWidget(col_5);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_8);

        col_6 = new QPushButton(frame);
        col_6->setObjectName("col_6");
        col_6->setMinimumSize(QSize(50, 50));
        col_6->setMaximumSize(QSize(50, 50));
        col_6->setStyleSheet(QString::fromUtf8("font-size: 20pt;"));

        horizontalLayout_13->addWidget(col_6);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_9);


        gridLayout->addLayout(horizontalLayout_13, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        Back = new QPushButton(frame);
        Back->setObjectName("Back");
        Back->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 238);\n"
"background-color: rgb(0, 173, 181);\n"
"font: 15pt \"MV Boli\";"));

        horizontalLayout_8->addWidget(Back);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        QPalette palette;
        QBrush brush(QColor(57, 62, 70, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        label_4->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Calligraphy")});
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("font: 22pt \"Lucida Calligraphy\";\n"
""));

        horizontalLayout_8->addWidget(label_4);

        Clear = new QPushButton(frame);
        Clear->setObjectName("Clear");
        Clear->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 238);\n"
"background-color: rgb(0, 173, 181);\n"
"font: 15pt \"MV Boli\";"));

        horizontalLayout_8->addWidget(Clear);


        gridLayout->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        Player1_name = new QLabel(frame);
        Player1_name->setObjectName("Player1_name");
        Player1_name->setMinimumSize(QSize(150, 0));
        Player1_name->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 238);\n"
"background-color: rgb(0, 173, 181);\n"
"font: 15pt \"MV Boli\";"));

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
        Player2_name->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 238);\n"
"background-color: rgb(0, 173, 181);\n"
"font: 15pt \"MV Boli\";"));

        horizontalLayout_5->addWidget(Player2_name);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setMinimumSize(QSize(163, 0));
        label->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 238);\n"
"background-color: rgb(0, 173, 181);\n"
"font: 15pt \"MV Boli\";"));

        horizontalLayout_7->addWidget(label);

        line_3 = new QFrame(frame);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_7->addWidget(line_3);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(150, 0));
        label_2->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_7->addWidget(label_2);

        line_2 = new QFrame(frame);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_7->addWidget(line_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(150, 0));
        label_3->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_7->addWidget(label_3);


        gridLayout_2->addLayout(horizontalLayout_7, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 9, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        c30 = new QPushButton(frame);
        c30->setObjectName("c30");
        c30->setEnabled(false);
        c30->setMinimumSize(QSize(75, 75));

        horizontalLayout_11->addWidget(c30);

        c31 = new QPushButton(frame);
        c31->setObjectName("c31");
        c31->setEnabled(false);
        c31->setMinimumSize(QSize(75, 75));

        horizontalLayout_11->addWidget(c31);

        c32 = new QPushButton(frame);
        c32->setObjectName("c32");
        c32->setEnabled(false);
        c32->setMinimumSize(QSize(75, 75));

        horizontalLayout_11->addWidget(c32);

        c33 = new QPushButton(frame);
        c33->setObjectName("c33");
        c33->setEnabled(false);
        c33->setMinimumSize(QSize(75, 75));

        horizontalLayout_11->addWidget(c33);

        c34 = new QPushButton(frame);
        c34->setObjectName("c34");
        c34->setEnabled(false);
        c34->setMinimumSize(QSize(75, 75));

        horizontalLayout_11->addWidget(c34);

        c35 = new QPushButton(frame);
        c35->setObjectName("c35");
        c35->setEnabled(false);
        c35->setMinimumSize(QSize(75, 75));

        horizontalLayout_11->addWidget(c35);

        c36 = new QPushButton(frame);
        c36->setObjectName("c36");
        c36->setEnabled(false);
        c36->setMinimumSize(QSize(75, 75));

        horizontalLayout_11->addWidget(c36);


        gridLayout->addLayout(horizontalLayout_11, 6, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        c10 = new QPushButton(frame);
        c10->setObjectName("c10");
        c10->setEnabled(false);
        c10->setMinimumSize(QSize(75, 75));
        c10->setMouseTracking(false);
        c10->setTabletTracking(false);
        c10->setCheckable(true);

        horizontalLayout_9->addWidget(c10);

        c11 = new QPushButton(frame);
        c11->setObjectName("c11");
        c11->setEnabled(false);
        c11->setMinimumSize(QSize(75, 75));

        horizontalLayout_9->addWidget(c11);

        c12 = new QPushButton(frame);
        c12->setObjectName("c12");
        c12->setEnabled(false);
        c12->setMinimumSize(QSize(75, 75));

        horizontalLayout_9->addWidget(c12);

        c13 = new QPushButton(frame);
        c13->setObjectName("c13");
        c13->setEnabled(false);
        c13->setMinimumSize(QSize(75, 75));

        horizontalLayout_9->addWidget(c13);

        c14 = new QPushButton(frame);
        c14->setObjectName("c14");
        c14->setEnabled(false);
        c14->setMinimumSize(QSize(75, 75));

        horizontalLayout_9->addWidget(c14);

        c15 = new QPushButton(frame);
        c15->setObjectName("c15");
        c15->setEnabled(false);
        c15->setMinimumSize(QSize(75, 75));

        horizontalLayout_9->addWidget(c15);

        c16 = new QPushButton(frame);
        c16->setObjectName("c16");
        c16->setEnabled(false);
        c16->setMinimumSize(QSize(75, 75));

        horizontalLayout_9->addWidget(c16);


        gridLayout->addLayout(horizontalLayout_9, 4, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        c50 = new QPushButton(frame);
        c50->setObjectName("c50");
        c50->setEnabled(false);
        c50->setMinimumSize(QSize(75, 75));
        c50->setMouseTracking(false);
        c50->setTabletTracking(false);
        c50->setCheckable(true);

        horizontalLayout_14->addWidget(c50);

        c51 = new QPushButton(frame);
        c51->setObjectName("c51");
        c51->setEnabled(false);
        c51->setMinimumSize(QSize(75, 75));
        c51->setMouseTracking(false);
        c51->setTabletTracking(false);
        c51->setCheckable(true);

        horizontalLayout_14->addWidget(c51);

        c52 = new QPushButton(frame);
        c52->setObjectName("c52");
        c52->setEnabled(false);
        c52->setMinimumSize(QSize(75, 75));

        horizontalLayout_14->addWidget(c52);

        c53 = new QPushButton(frame);
        c53->setObjectName("c53");
        c53->setEnabled(false);
        c53->setMinimumSize(QSize(75, 75));

        horizontalLayout_14->addWidget(c53);

        c54 = new QPushButton(frame);
        c54->setObjectName("c54");
        c54->setEnabled(false);
        c54->setMinimumSize(QSize(75, 75));

        horizontalLayout_14->addWidget(c54);

        c55 = new QPushButton(frame);
        c55->setObjectName("c55");
        c55->setEnabled(false);
        c55->setMinimumSize(QSize(75, 75));

        horizontalLayout_14->addWidget(c55);

        c56 = new QPushButton(frame);
        c56->setObjectName("c56");
        c56->setEnabled(false);
        c56->setMinimumSize(QSize(75, 75));

        horizontalLayout_14->addWidget(c56);


        gridLayout->addLayout(horizontalLayout_14, 8, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);


        gridLayout_3->addWidget(frame, 1, 1, 2, 1);

        horizontalSpacer_10 = new QSpacerItem(121, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_10, 2, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(120, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_11, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 628, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 1, 1, 1);

        Connect4->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Connect4);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1030, 25));
        Connect4->setMenuBar(menubar);
        statusbar = new QStatusBar(Connect4);
        statusbar->setObjectName("statusbar");
        Connect4->setStatusBar(statusbar);

        retranslateUi(Connect4);

        QMetaObject::connectSlotsByName(Connect4);
    } // setupUi

    void retranslateUi(QMainWindow *Connect4)
    {
        Connect4->setWindowTitle(QCoreApplication::translate("Connect4", "MainWindow", nullptr));
        c20->setText(QString());
        c21->setText(QString());
        c22->setText(QString());
        c23->setText(QString());
        c24->setText(QString());
        c25->setText(QString());
        c26->setText(QString());
        c00->setText(QString());
        c01->setText(QString());
        c02->setText(QString());
        c03->setText(QString());
        c04->setText(QString());
        c05->setText(QString());
        c06->setText(QString());
        c40->setText(QString());
        c41->setText(QString());
        c42->setText(QString());
        c43->setText(QString());
        c44->setText(QString());
        c45->setText(QString());
        c46->setText(QString());
        col_0->setText(QCoreApplication::translate("Connect4", "\342\254\207\357\270\217", nullptr));
        col_1->setText(QCoreApplication::translate("Connect4", "\342\254\207\357\270\217", nullptr));
        col_2->setText(QCoreApplication::translate("Connect4", "\342\254\207\357\270\217", nullptr));
        col_3->setText(QCoreApplication::translate("Connect4", "\342\254\207\357\270\217", nullptr));
        col_4->setText(QCoreApplication::translate("Connect4", "\342\254\207\357\270\217", nullptr));
        col_5->setText(QCoreApplication::translate("Connect4", "\342\254\207\357\270\217", nullptr));
        col_6->setText(QCoreApplication::translate("Connect4", "\342\254\207\357\270\217", nullptr));
        Back->setText(QCoreApplication::translate("Connect4", "Back", nullptr));
        label_4->setText(QCoreApplication::translate("Connect4", "Connect Four", nullptr));
        Clear->setText(QCoreApplication::translate("Connect4", "Clear", nullptr));
        Player1_name->setText(QCoreApplication::translate("Connect4", "Player1", nullptr));
        Player2_name->setText(QCoreApplication::translate("Connect4", "Player2", nullptr));
        label->setText(QCoreApplication::translate("Connect4", "Score", nullptr));
        label_2->setText(QCoreApplication::translate("Connect4", "0", nullptr));
        label_3->setText(QCoreApplication::translate("Connect4", "0", nullptr));
        c30->setText(QString());
        c31->setText(QString());
        c32->setText(QString());
        c33->setText(QString());
        c34->setText(QString());
        c35->setText(QString());
        c36->setText(QString());
        c10->setText(QString());
        c11->setText(QString());
        c12->setText(QString());
        c13->setText(QString());
        c14->setText(QString());
        c15->setText(QString());
        c16->setText(QString());
        c50->setText(QString());
        c51->setText(QString());
        c52->setText(QString());
        c53->setText(QString());
        c54->setText(QString());
        c55->setText(QString());
        c56->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Connect4: public Ui_Connect4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT4_H
