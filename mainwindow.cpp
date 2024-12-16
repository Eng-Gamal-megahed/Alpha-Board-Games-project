#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "basic.h"
#include "pyramic.h"
#include "fivexfive.h"
#include "word.h"
#include "numaric.h"
#include "inverse.h"
#include "fourxfour.h"
#include "sus.h"
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix1("VS_Photo.png");
    ui->label_2->setPixmap(pix1);
    QPixmap pix2("Gamal games.png");
    ui->label_3->setPixmap(pix2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Game_Mode_currentTextChanged(const QString &player_type)
{
    QMediaPlayer *click = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    click->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    click->setSource(QUrl::fromLocalFile("click.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    click->play();
    if(player_type == "Human Player")
    {
        ui->Player2->clear();
        ui->Player2->setReadOnly(false);
    }

    if(player_type == "Random Player")
    {
        ui->Player2->setText("Random Player");
        ui->Player2->setReadOnly(true);
    }

    if(player_type == "AI Player")
    {
        ui->Player2->setText("AI Player");
        ui->Player2->setReadOnly(true);
    }
}


void MainWindow::on_pushButton_clicked()
{
    QMediaPlayer *click = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    click->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    click->setSource(QUrl::fromLocalFile("click.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    click->play();
    QString game = ui->Game->currentText();
    if(game == "Basic Tic Tac Toe")
    {
        Basic *basic = new Basic();
        basic->show();
        basic->setNames(ui->Player1->text() , ui->Player2->text());
        this->close();
    }

    if(game == "Pyramic Tic-Tac-Toe")
    {
        PYRAMIC *pyramicWindow = new PYRAMIC();
        pyramicWindow->show();
        pyramicWindow->setNames(ui->Player1->text() , ui->Player2->text());
        this->close();
    }


    if(game == "5 x 5 Tic Tac Toe")
    {
        FiveXFive *fivexfive = new FiveXFive();
        fivexfive->show();
        fivexfive->setNames(ui->Player1->text() , ui->Player2->text());
        this->close();
    }

    if(game == "Word Tic-tac-toe")
    {
        Word *word = new Word();
        word->show();
        word->setNames(ui->Player1->text() , ui->Player2->text());
        this->close();
    }

    if(game == "Numerical Tic-Tac-Toe")
    {
        Numaric *numaric = new Numaric();
        numaric->show();
        numaric->setNames(ui->Player1->text() , ui->Player2->text());
        this->close();
    }

    if(game == "Inverse Tic Tac Toe")
    {
        Inverse *inverse = new Inverse();
        inverse->show();
        inverse->setNames(ui->Player1->text() , ui->Player2->text());
        this->close();
    }

    if(game == "4 x 4 Tic-Tac-Toe")
    {
        FourXFour *fourxfour = new FourXFour();
        fourxfour->setNames(ui->Player1->text() , ui->Player2->text());
        this->close();
        fourxfour->show();
    }

    if(game == "SUS Game")
    {
        SUS *sus = new SUS();
        sus->show();
        sus->setNames(ui->Player1->text() , ui->Player2->text());
        this->close();
    }
}


void MainWindow::on_Game_currentTextChanged(const QString &arg1)
{
    QMediaPlayer *click = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    click->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    click->setSource(QUrl::fromLocalFile("click.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    click->play();
}

