#include "basic.h"
#include "ui_basic.h"
#include "mainwindow.h"
#include <iomanip>
#include <QMessageBox>
#include <QPushButton>


Basic::Basic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Basic)
{
    ui->setupUi(this);
    ui->Player1_name->setAlignment(Qt::AlignCenter);
    ui->p1_score->setAlignment(Qt::AlignCenter);
    ui->p2_score->setAlignment(Qt::AlignCenter);
    ui->Player2_name->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
}


Basic::~Basic()
{
    delete ui;
}

template <typename T>
X_O_Board<T>::X_O_Board() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool X_O_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void X_O_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool X_O_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0)) {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) {
        return true;
    }

    return false;
}

// Return true if 9 moves_B are done and no winner
template <typename T>
bool X_O_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool X_O_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}


Board<char>* B = new X_O_Board<char>();
int moves_B = 0 , p1_score_B = 0 , p2_score_B = 0;
vector<int>clicked(9);



void Basic::setNames(QString p1 , QString p2)
{
    ui->Player1_name->setText(p1);
    ui->Player2_name->setText(p2);
    p1_score_B = p2_score_B = 0;
}







void Basic::on_Clear_clicked()
{
    ui->cell_00->setText("");
    ui->cell_01->setText("");
    ui->cell_02->setText("");
    ui->cell_10->setText("");
    ui->cell_11->setText("");
    ui->cell_12->setText("");
    ui->cell_20->setText("");
    ui->cell_21->setText("");
    ui->cell_22->setText("");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            B->update_board(i , j , 0);
        }
    }
    clicked = vector<int>(9);
    moves_B = 0;
}

void draw(QWidget *parent) {
    // Create a media player instance
    QMediaPlayer *draw = new QMediaPlayer(parent);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(parent);
    draw->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    draw->setSource(QUrl::fromLocalFile("lose.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    draw->play();

    // Show the message box non-modally
    QMessageBox *msgBox = new QMessageBox(static_cast<QWidget *>(parent));
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setWindowTitle("Game Over");
    msgBox->setText("Tie.");
    msgBox->setStyleSheet("QLabel{ font-size: 18px; }");

    // Resize the message box
    msgBox->setFixedSize(400, 200);  // Set the width and height of the box
    msgBox->show();

    // Continuously process events to ensure audio playback continues
    while (msgBox->isVisible()) {
        QApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    // Cleanup (optional)
    delete draw;
    delete audioOutput;
}

void win(QWidget *parent , QString winner)
{
    // Create a media player instance
    QMediaPlayer *win = new QMediaPlayer(parent);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(parent);
    win->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path for the "win" sound)
    win->setSource(QUrl::fromLocalFile("win.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    win->play();

    // Show the "win" message box non-modally
    QMessageBox *msgBox = new QMessageBox(static_cast<QWidget *>(parent));
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setWindowTitle("Game Over");
    msgBox->setText(winner + " Wins!");
    msgBox->setStyleSheet("QLabel{ font-size: 18px; }");

    // Resize the message box
    msgBox->setFixedSize(400, 200);  // Set the width and height of the box
    msgBox->show();

    // Continuously process events to ensure audio playback continues
    while (msgBox->isVisible()) {
        QApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    // Cleanup (optional)
    delete win;
    delete audioOutput;
}

#include <QRandomGenerator>

// Function to make a random move for Player 2
void Basic::makeRandomMove() {
    int x, y;
    do {
        // Generate random row and column between 0 and 2
        x = QRandomGenerator::global()->bounded(0, 3);
        y = QRandomGenerator::global()->bounded(0, 3);
    } while (clicked[x * 3 + y]); // Repeat until an empty cell is found

    // Update the board and UI with Player 2's move
    QString cellName = QString("cell_%1%2").arg(x).arg(y);
    QPushButton* button = this->findChild<QPushButton*>(cellName);
    if (button) {
        button->setText("O");
        button->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B->update_board(x, y, 'O');
        clicked[x * 3 + y] = 1;
        moves_B++;
    }

    // Check for win or draw after the move
    if (B->is_win()) {
        ui->p2_score->setText(QString::number(++p2_score_B));
        win(this, ui->Player2_name->text());
        this->on_Clear_clicked();
    } else if (moves_B == 9) {
        draw(this); return;
        this->on_Clear_clicked();
    }
}



void Basic::on_cell_00_clicked()
{
    QMediaPlayer *player = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    player->setSource(QUrl::fromLocalFile("play.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    player->play();
    if(clicked[0]++)
    {
        return;
    }
    if(moves_B & 1)
    {
        ui->cell_00->setText("O");
        ui->cell_00->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B->update_board(0 , 0 , 'O');
    }
    else
    {
        ui->cell_00->setText("X");
        ui->cell_00->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B->update_board(0 , 0 , 'X');
    }
    if(B->is_win())
    {
        if(moves_B & 1)
        {
            ui->p2_score->setText(QString::number(++p2_score_B));
        }
        else
        {
            ui->p1_score->setText(QString::number(++p1_score_B));

        }
        win(this , (moves_B & 1)? ui->Player2_name->text() : ui->Player1_name->text());
        this->on_Clear_clicked();
        return;
    }
    moves_B++;
    if(moves_B == 9)
    {
        this->on_Clear_clicked();
        draw(this); return;
    }
        if(ui->Player2_name->text() == "Random Player")
    {
        makeRandomMove();
    }
        if(ui->Player2_name->text() == "AI Player")
        {
            makeCalclutedMove();
        }
}


void Basic::on_cell_01_clicked()
{
    QMediaPlayer *player = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    player->setSource(QUrl::fromLocalFile("play.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    player->play();
    if(clicked[1]++)
    {
        return;
    }
    if(moves_B & 1)
    {
        ui->cell_01->setText("O");
        ui->cell_01->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B->update_board(0 , 1 , 'O');
    }
    else
    {
        ui->cell_01->setText("X");
        ui->cell_01->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B->update_board(0 , 1 , 'X');
    }
    if(B->is_win())
    {
        if(moves_B & 1)
        {
            ui->p2_score->setText(QString::number(++p2_score_B));
        }
        else
        {
            ui->p1_score->setText(QString::number(++p1_score_B));

        }
        win(this , (moves_B & 1)? ui->Player2_name->text() : ui->Player1_name->text());
        this->on_Clear_clicked();
        return;
    }
    moves_B++;
    if(moves_B == 9)
    {
        this->on_Clear_clicked();
        draw(this); return;
    }
    if(ui->Player2_name->text() == "Random Player")
    {
        makeRandomMove();
    }
    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalclutedMove();
    }
}


void Basic::on_cell_02_clicked()
{
    QMediaPlayer *player = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    player->setSource(QUrl::fromLocalFile("play.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    player->play();
    if(clicked[2]++)
    {
        return;
    }
    if(moves_B & 1)
    {
        ui->cell_02->setText("O");
        ui->cell_02->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B->update_board(0 , 2 , 'O');
    }
    else
    {
        ui->cell_02->setText("X");
        ui->cell_02->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B->update_board(0 , 2 , 'X');
    }
    if(B->is_win())
    {
        if(moves_B & 1)
        {
            ui->p2_score->setText(QString::number(++p2_score_B));
        }
        else
        {
            ui->p1_score->setText(QString::number(++p1_score_B));

        }
        win(this , (moves_B & 1)? ui->Player2_name->text() : ui->Player1_name->text());
        this->on_Clear_clicked();
        return;
    }
    moves_B++;
    if(moves_B == 9)
    {
        this->on_Clear_clicked();
        draw(this); return;
    }
    if(ui->Player2_name->text() == "Random Player")
    {
        makeRandomMove();
    }
    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalclutedMove();
    }
}


void Basic::on_cell_10_clicked()
{
    QMediaPlayer *player = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    player->setSource(QUrl::fromLocalFile("play.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    player->play();
    if(clicked[3]++)
    {
        return;
    }
    if(moves_B & 1)
    {
        ui->cell_10->setText("O");
        ui->cell_10->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B->update_board(1 , 0 , 'O');
    }
    else
    {
        ui->cell_10->setText("X");
        ui->cell_10->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B->update_board(1 , 0 , 'X');
    }
    if(B->is_win())
    {
        if(moves_B & 1)
        {
            ui->p2_score->setText(QString::number(++p2_score_B));
        }
        else
        {
            ui->p1_score->setText(QString::number(++p1_score_B));

        }
        win(this , (moves_B & 1)? ui->Player2_name->text() : ui->Player1_name->text());
        this->on_Clear_clicked();
        return;
    }
    moves_B++;
    if(moves_B == 9)
    {
        this->on_Clear_clicked();
        draw(this); return;
    }
    if(ui->Player2_name->text() == "Random Player")
    {
        makeRandomMove();
    }
    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalclutedMove();
    }
}


void Basic::on_cell_11_clicked()
{
    QMediaPlayer *player = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    player->setSource(QUrl::fromLocalFile("play.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    player->play();
    if(clicked[4]++)
    {
        return;
    }
    if(moves_B & 1)
    {
        ui->cell_11->setText("O");
        ui->cell_11->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B->update_board(1 , 1 , 'O');
    }
    else
    {
        ui->cell_11->setText("X");
        ui->cell_11->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B->update_board(1 , 1 , 'X');
    }
    if(B->is_win())
    {
        if(moves_B & 1)
        {
            ui->p2_score->setText(QString::number(++p2_score_B));
        }
        else
        {
            ui->p1_score->setText(QString::number(++p1_score_B));

        }
        win(this , (moves_B & 1)? ui->Player2_name->text() : ui->Player1_name->text());
        this->on_Clear_clicked();
        return;
    }
    moves_B++;
    if(moves_B == 9)
    {
        this->on_Clear_clicked();
        draw(this); return;
    }
    if(ui->Player2_name->text() == "Random Player")
    {
        makeRandomMove();
    }
    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalclutedMove();
    }
}


void Basic::on_cell_12_clicked()
{
    QMediaPlayer *player = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    player->setSource(QUrl::fromLocalFile("play.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    player->play();
    if(clicked[5]++)
    {
        return;
    }
    if(moves_B & 1)
    {
        ui->cell_12->setText("O");
        ui->cell_12->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B->update_board(1 , 2 , 'O');
    }
    else
    {
        ui->cell_12->setText("X");
        ui->cell_12->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B->update_board(1 , 2 , 'X');
    }
    if(B->is_win())
    {
        if(moves_B & 1)
        {
            ui->p2_score->setText(QString::number(++p2_score_B));
        }
        else
        {
            ui->p1_score->setText(QString::number(++p1_score_B));

        }
        win(this , (moves_B & 1)? ui->Player2_name->text() : ui->Player1_name->text());
        this->on_Clear_clicked();
        return;
    }
    moves_B++;
    if(moves_B == 9)
    {
        this->on_Clear_clicked();
        draw(this); return;
    }
    if(ui->Player2_name->text() == "Random Player")
    {
        makeRandomMove();
    }

    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalclutedMove();
    }
}


void Basic::on_cell_20_clicked()
{
    QMediaPlayer *player = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    player->setSource(QUrl::fromLocalFile("play.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    player->play();
    if(clicked[6]++)
    {
        return;
    }
    if(moves_B & 1)
    {
        ui->cell_20->setText("O");
        ui->cell_20->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B->update_board(2 , 0 , 'O');
    }
    else
    {
        ui->cell_20->setText("X");
        ui->cell_20->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B->update_board(2 , 0 , 'X');
    }
    if(B->is_win())
    {
        if(moves_B & 1)
        {
            ui->p2_score->setText(QString::number(++p2_score_B));
        }
        else
        {
            ui->p1_score->setText(QString::number(++p1_score_B));

        }
        win(this , (moves_B & 1)? ui->Player2_name->text() : ui->Player1_name->text());
        this->on_Clear_clicked();
        return;
    }
    moves_B++;
    if(moves_B == 9)
    {
        this->on_Clear_clicked();
        draw(this); return;
    }
    if(ui->Player2_name->text() == "Random Player")
    {
        makeRandomMove();
    }
    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalclutedMove();
    }
}


void Basic::on_cell_21_clicked()
{
    QMediaPlayer *player = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    player->setSource(QUrl::fromLocalFile("play.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    player->play();
    if(clicked[7]++)
    {
        return;
    }
    if(moves_B & 1)
    {
        ui->cell_21->setText("O");
        ui->cell_21->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B->update_board(2 , 1 , 'O');
    }
    else
    {
        ui->cell_21->setText("X");
        ui->cell_21->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B->update_board(2 , 1 , 'X');
    }
    if(B->is_win())
    {
        if(moves_B & 1)
        {
            ui->p2_score->setText(QString::number(++p2_score_B));
        }
        else
        {
            ui->p1_score->setText(QString::number(++p1_score_B));

        }
        win(this , (moves_B & 1)? ui->Player2_name->text() : ui->Player1_name->text());
        this->on_Clear_clicked();
        return;
    }
    moves_B++;
    if(moves_B == 9)
    {
        this->on_Clear_clicked();
        draw(this); return;
    }
    if(ui->Player2_name->text() == "Random Player")
    {
        makeRandomMove();
    }
    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalclutedMove();
    }
}


void Basic::on_cell_22_clicked()
{
    QMediaPlayer *player = new QMediaPlayer(this);

    // Create an audio output instance
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Set the audio file (use an absolute or relative path)
    player->setSource(QUrl::fromLocalFile("play.wav"));

    // Set the volume (optional)
    audioOutput->setVolume(0.5);  // Volume is between 0.0 and 1.0

    // Play the audio
    player->play();
    if(clicked[8]++)
    {
        return;
    }
    if(moves_B & 1)
    {
        ui->cell_22->setText("O");
        ui->cell_22->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B->update_board(2 , 2 , 'O');
    }
    else
    {
        ui->cell_22->setText("X");
        ui->cell_22->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B->update_board(2 , 2 , 'X');
    }
    if(B->is_win())
    {
        if(moves_B & 1)
        {
            ui->p2_score->setText(QString::number(++p2_score_B));
        }
        else
        {
            ui->p1_score->setText(QString::number(++p1_score_B));

        }
        win(this , (moves_B & 1)? ui->Player2_name->text() : ui->Player1_name->text());
        this->on_Clear_clicked();
        return;
    }
    moves_B++;
    if(moves_B == 9)
    {
        this->on_Clear_clicked();
        draw(this);
        return;
    }
    if(ui->Player2_name->text() == "Random Player")
    {
        makeRandomMove();
    }
    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalclutedMove();
    }
}



void Basic::on_Back_clicked()
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
    this->on_Clear_clicked();
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
    this->close();
}

void Basic::makeCalclutedMove()
{
    // check if i can win in the next move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(!B->update_board(i , j , 'O'))
                continue;
            if(B->is_win())
            {
                moves_B++;
                QString cellName = "cell_" + QString::number(i) + QString::number(j);
                QPushButton *cellButton = findChild<QPushButton*>(cellName);
                if (cellButton) {
                    cellButton->setText("O");
                    cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: red ; font-size: 28pt; font-weight: bold;");
                }
                clicked[i * 3 + j]++;
                ui->p2_score->setText(QString::number(++p2_score_B));
                win(this, ui->Player2_name->text());
                this->on_Clear_clicked();
                return;
            }
            B->update_board(i , j , 0);
        }
    }

    // check if the oppennet can win in the next move

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(!B->update_board(i , j , 'X'))
                continue;
            if(B->is_win())
            {
                B->update_board(i , j , 0);
                B->update_board(i , j , 'O');
                moves_B++;
                QString cellName = "cell_" + QString::number(i) + QString::number(j);
                QPushButton *cellButton = findChild<QPushButton*>(cellName);
                if (cellButton) {
                    cellButton->setText("O");
                    cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: red ; font-size: 28pt; font-weight: bold;");
                }
                clicked[i * 3 + j]++;
                return;
            }
            B->update_board(i , j , 0);
        }
    }

    // if no good move make a random move
    makeRandomMove();
}

