/********************************************************************************
** Form generated from reading UI file 'word.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORD_H
#define UI_WORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_Word
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *cell_00;
    QPushButton *cell_01;
    QPushButton *cell_02;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *cell_10;
    QPushButton *cell_11;
    QPushButton *cell_12;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *cell_20;
    QPushButton *cell_21;
    QPushButton *cell_22;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_11;
    QFrame *line_7;
    QLabel *Player1_name;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Player2_name;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QFrame *line_5;
    QLabel *p1_score;
    QFrame *line_6;
    QLabel *p2_score;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *Back_4;
    QComboBox *enabled_chars;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *Back;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Clear;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Word)
    {
        if (Word->objectName().isEmpty())
            Word->setObjectName("Word");
        Word->resize(782, 653);
        Word->setStyleSheet(QString::fromUtf8("background-color: #021a1a;"));
        centralwidget = new QWidget(Word);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(152, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setStyleSheet(QString::fromUtf8("background-color: #00df83;"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 5, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);

        cell_00 = new QPushButton(frame_2);
        cell_00->setObjectName("cell_00");
        cell_00->setMinimumSize(QSize(75, 75));
        cell_00->setMaximumSize(QSize(75, 75));
        cell_00->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_3->addWidget(cell_00);

        cell_01 = new QPushButton(frame_2);
        cell_01->setObjectName("cell_01");
        cell_01->setMinimumSize(QSize(75, 75));
        cell_01->setMaximumSize(QSize(75, 16777215));
        cell_01->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_3->addWidget(cell_01);

        cell_02 = new QPushButton(frame_2);
        cell_02->setObjectName("cell_02");
        cell_02->setMinimumSize(QSize(75, 75));
        cell_02->setMaximumSize(QSize(75, 16777215));
        cell_02->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_3->addWidget(cell_02);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_14);

        cell_10 = new QPushButton(frame_2);
        cell_10->setObjectName("cell_10");
        cell_10->setMinimumSize(QSize(75, 75));
        cell_10->setMaximumSize(QSize(75, 16777215));
        cell_10->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout->addWidget(cell_10);

        cell_11 = new QPushButton(frame_2);
        cell_11->setObjectName("cell_11");
        cell_11->setMinimumSize(QSize(75, 75));
        cell_11->setMaximumSize(QSize(75, 16777215));
        cell_11->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout->addWidget(cell_11);

        cell_12 = new QPushButton(frame_2);
        cell_12->setObjectName("cell_12");
        cell_12->setMinimumSize(QSize(75, 75));
        cell_12->setMaximumSize(QSize(75, 75));
        cell_12->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout->addWidget(cell_12);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_15);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_16);

        cell_20 = new QPushButton(frame_2);
        cell_20->setObjectName("cell_20");
        cell_20->setMinimumSize(QSize(75, 75));
        cell_20->setMaximumSize(QSize(75, 75));
        cell_20->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_2->addWidget(cell_20);

        cell_21 = new QPushButton(frame_2);
        cell_21->setObjectName("cell_21");
        cell_21->setMinimumSize(QSize(75, 75));
        cell_21->setMaximumSize(QSize(75, 75));
        cell_21->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_2->addWidget(cell_21);

        cell_22 = new QPushButton(frame_2);
        cell_22->setObjectName("cell_22");
        cell_22->setMinimumSize(QSize(75, 75));
        cell_22->setMaximumSize(QSize(75, 75));
        cell_22->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 26, 26);\n"
""));

        horizontalLayout_2->addWidget(cell_22);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_17);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        line_7 = new QFrame(frame_2);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::Shape::VLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_4->addWidget(line_7);

        Player1_name = new QLabel(frame_2);
        Player1_name->setObjectName("Player1_name");
        Player1_name->setMinimumSize(QSize(149, 0));
        Player1_name->setMaximumSize(QSize(149, 16777215));
        Player1_name->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 16pt;\n"
"font-weight: bold;\n"
""));

        horizontalLayout_4->addWidget(Player1_name);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        line_4 = new QFrame(frame_2);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::Shape::VLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_6->addWidget(line_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        Player2_name = new QLabel(frame_2);
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
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setMinimumSize(QSize(163, 0));
        label->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 16pt;\n"
"font-weight: bold;\n"
""));

        horizontalLayout_7->addWidget(label);

        line_5 = new QFrame(frame_2);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::Shape::VLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_7->addWidget(line_5);

        p1_score = new QLabel(frame_2);
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

        line_6 = new QFrame(frame_2);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::Shape::VLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_7->addWidget(line_6);

        p2_score = new QLabel(frame_2);
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


        gridLayout->addLayout(gridLayout_2, 6, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        Back_4 = new QPushButton(frame_2);
        Back_4->setObjectName("Back_4");
        Back_4->setEnabled(false);
        Back_4->setMinimumSize(QSize(0, 30));
        Back_4->setMaximumSize(QSize(16777215, 40));
        Back_4->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 16pt;\n"
"font-weight: bold;\n"
""));

        horizontalLayout_9->addWidget(Back_4);

        enabled_chars = new QComboBox(frame_2);
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->addItem(QString());
        enabled_chars->setObjectName("enabled_chars");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(enabled_chars->sizePolicy().hasHeightForWidth());
        enabled_chars->setSizePolicy(sizePolicy);
        enabled_chars->setMinimumSize(QSize(350, 30));
        enabled_chars->setMaximumSize(QSize(30, 40));
        enabled_chars->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 15pt;\n"
"padding: 10px;"));

        horizontalLayout_9->addWidget(enabled_chars);


        gridLayout->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        Back = new QPushButton(frame_2);
        Back->setObjectName("Back");
        Back->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 15pt;\n"
"padding: 16px;"));

        horizontalLayout_8->addWidget(Back);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
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
        label_5->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("font: 22pt \"Arial Rounded MT Bold\";\n"
"color: #021a1a;\n"
"margin: 16pt;"));

        horizontalLayout_8->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        Clear = new QPushButton(frame_2);
        Clear->setObjectName("Clear");
        Clear->setStyleSheet(QString::fromUtf8("color: 14213d;\n"
"background-color: #021a1a;\n"
"border-radius: 10px;  \n"
"font-size : 15pt;\n"
"padding: 16px;"));

        horizontalLayout_8->addWidget(Clear);


        gridLayout->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 3, 0, 1, 1);


        gridLayout_3->addWidget(frame_2, 1, 1, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(151, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 3, 1, 1, 1);

        Word->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Word);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 782, 25));
        Word->setMenuBar(menubar);
        statusbar = new QStatusBar(Word);
        statusbar->setObjectName("statusbar");
        Word->setStatusBar(statusbar);

        retranslateUi(Word);

        QMetaObject::connectSlotsByName(Word);
    } // setupUi

    void retranslateUi(QMainWindow *Word)
    {
        Word->setWindowTitle(QCoreApplication::translate("Word", "MainWindow", nullptr));
        cell_00->setText(QString());
        cell_01->setText(QString());
        cell_02->setText(QString());
        cell_10->setText(QString());
        cell_11->setText(QString());
        cell_12->setText(QString());
        cell_20->setText(QString());
        cell_21->setText(QString());
        cell_22->setText(QString());
        Player1_name->setText(QCoreApplication::translate("Word", "Player1", nullptr));
        Player2_name->setText(QCoreApplication::translate("Word", "Player2", nullptr));
        label->setText(QCoreApplication::translate("Word", "Score", nullptr));
        p1_score->setText(QCoreApplication::translate("Word", "0", nullptr));
        p2_score->setText(QCoreApplication::translate("Word", "0", nullptr));
        Back_4->setText(QCoreApplication::translate("Word", "Latter ", nullptr));
        enabled_chars->setItemText(0, QCoreApplication::translate("Word", "A", nullptr));
        enabled_chars->setItemText(1, QCoreApplication::translate("Word", "B", nullptr));
        enabled_chars->setItemText(2, QCoreApplication::translate("Word", "C", nullptr));
        enabled_chars->setItemText(3, QCoreApplication::translate("Word", "D", nullptr));
        enabled_chars->setItemText(4, QCoreApplication::translate("Word", "E", nullptr));
        enabled_chars->setItemText(5, QCoreApplication::translate("Word", "F", nullptr));
        enabled_chars->setItemText(6, QCoreApplication::translate("Word", "G", nullptr));
        enabled_chars->setItemText(7, QCoreApplication::translate("Word", "H", nullptr));
        enabled_chars->setItemText(8, QCoreApplication::translate("Word", "I", nullptr));
        enabled_chars->setItemText(9, QCoreApplication::translate("Word", "J", nullptr));
        enabled_chars->setItemText(10, QCoreApplication::translate("Word", "K", nullptr));
        enabled_chars->setItemText(11, QCoreApplication::translate("Word", "L", nullptr));
        enabled_chars->setItemText(12, QCoreApplication::translate("Word", "M", nullptr));
        enabled_chars->setItemText(13, QCoreApplication::translate("Word", "N", nullptr));
        enabled_chars->setItemText(14, QCoreApplication::translate("Word", "O", nullptr));
        enabled_chars->setItemText(15, QCoreApplication::translate("Word", "P", nullptr));
        enabled_chars->setItemText(16, QCoreApplication::translate("Word", "Q", nullptr));
        enabled_chars->setItemText(17, QCoreApplication::translate("Word", "R", nullptr));
        enabled_chars->setItemText(18, QCoreApplication::translate("Word", "S", nullptr));
        enabled_chars->setItemText(19, QCoreApplication::translate("Word", "T", nullptr));
        enabled_chars->setItemText(20, QCoreApplication::translate("Word", "U", nullptr));
        enabled_chars->setItemText(21, QCoreApplication::translate("Word", "V", nullptr));
        enabled_chars->setItemText(22, QCoreApplication::translate("Word", "W", nullptr));
        enabled_chars->setItemText(23, QCoreApplication::translate("Word", "X", nullptr));
        enabled_chars->setItemText(24, QCoreApplication::translate("Word", "Y", nullptr));
        enabled_chars->setItemText(25, QCoreApplication::translate("Word", "Z", nullptr));

        Back->setText(QCoreApplication::translate("Word", "Back", nullptr));
        label_5->setText(QCoreApplication::translate("Word", "Word Tic-Tac-Toe", nullptr));
        Clear->setText(QCoreApplication::translate("Word", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Word: public Ui_Word {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORD_H
