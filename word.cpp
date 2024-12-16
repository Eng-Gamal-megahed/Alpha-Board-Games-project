#include "word.h"
#include "ui_word.h"
#include "mainwindow.h"
#include <fstream>
#include <QMessageBox>
#include <iomanip>
#include <algorithm>
template <typename T>
Word_TIC_TAC_TOE_Board<T>::Word_TIC_TAC_TOE_Board() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;

    ifstream dict("dic.txt");

    string word;
    while (getline(dict , word))
    {
        this->is_valid[word] = true;
    }
    dict.close();
}

template <typename T>
bool Word_TIC_TAC_TOE_Board<T>::update_board(int x, int y, T mark) {
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
void Word_TIC_TAC_TOE_Board<T>::display_board() {
    cout << "\n-----------------------------";
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
bool Word_TIC_TAC_TOE_Board<T>::is_win() {

    for (int i = 0; i < this->rows; i++) {
        string row = string(1, this->board[i][0]) + string(1, this->board[i][1]) + string(1, this->board[i][2]);
        string col = string(1, this->board[0][i]) + string(1, this->board[1][i]) + string(1, this->board[2][i]);

        if (this->is_valid[row] ||
            this->is_valid[col]) {
            return true;
        }
        reverse(row.begin() , row.end());
        reverse(col.begin() , col.end());
        if (this->is_valid[row] ||
            this->is_valid[col]) {
            return true;
        }
    }

    // Check diagonals
    string left_right_diag = string(1, this->board[0][0]) + string(1, this->board[1][1]) + string(1, this->board[2][2]);
    string right_left_diag = string(1, this->board[0][2]) + string(1, this->board[1][1]) + string(1, this->board[2][0]);

    if (this->is_valid[left_right_diag] ||
        this->is_valid[right_left_diag]) {
        return true;
    }
    reverse(left_right_diag.begin() , left_right_diag.end());
    reverse(right_left_diag.begin() , right_left_diag.end());
    if (this->is_valid[left_right_diag] ||
        this->is_valid[right_left_diag]) {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool Word_TIC_TAC_TOE_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Word_TIC_TAC_TOE_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

Word::Word(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Word)
{
    ui->setupUi(this);
    ui->Player1_name->setAlignment(Qt::AlignCenter);
    ui->p1_score->setAlignment(Qt::AlignCenter);
    ui->p2_score->setAlignment(Qt::AlignCenter);
    ui->Player2_name->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
}

Word::~Word()
{
    delete ui;
}

void Word::setNames(QString p1 , QString p2)
{
    ui->Player1_name->setText(p1);
    ui->Player2_name->setText(p2);
}


void Word::on_Back_clicked()
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
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
    on_Clear_clicked();
    this->close();
}

void draw_W(QWidget *parent) {
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

void win_W(QWidget *parent , QString winner)
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

int moves_W = 0 , p1_score_W = 0 , p2_score_W = 0;
vector<int>clicked_W(9 , 0);
Board<char>* B_W = new Word_TIC_TAC_TOE_Board<char>;

#include <QRandomGenerator>

void Word::makeRandomMove() {
    int x, y;
    char letter = QRandomGenerator::global()->bounded(0, 26) + 'A';
    do {
        // Generate random row and column between 0 and 2
        x = QRandomGenerator::global()->bounded(0, 3);
        y = QRandomGenerator::global()->bounded(0, 3);
    } while (clicked_W[x * 3 + y]); // Repeat until an empty cell is found

    // Update the board and UI with Player 2's move
    QString cellName = QString("cell_%1%2").arg(x).arg(y);
    QPushButton* button = this->findChild<QPushButton*>(cellName);
    if (button) {
        button->setText(QString(letter));
        button->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B_W->update_board(x, y, letter);
        clicked_W[x * 3 + y] = 1;
        moves_W++;
    }

    // Check for win or draw after the move
    if (B_W->is_win()) {
        ui->p2_score->setText(QString::number(++p2_score_W));
        win_W(this, ui->Player2_name->text());
        this->on_Clear_clicked();
    } else if (moves_W == 9) {
        draw_W(this); return;
        this->on_Clear_clicked();
    }
}

void Word::handle_cell(int x , int y , char l)
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
    if (clicked_W[x * 3 + y]++) {
        return; // Ignore if the cell is already clicked
    }

    QString mark = QString(l);
    QString color = "blue";

    // Update the board and the corresponding button
    QString cellName = "cell_" + QString::number(x) + QString::number(y);
    QPushButton *cellButton = findChild<QPushButton*>(cellName);
    if (cellButton) {
        cellButton->setText(mark);
        cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: " + color + "; font-size: 28pt; font-weight: bold;");
    }

    B_W->update_board(x , y , l);

    // Check for win
    if (B_W->is_win()) {
        if (moves_W & 1) {
            ui->p2_score->setText(QString::number(++p2_score_W));
        } else {
            ui->p1_score->setText(QString::number(++p1_score_W));
        }
        win_W(this, (moves_W & 1) ? ui->Player2_name->text() : ui->Player1_name->text());
        on_Clear_clicked();
        return;
    }

    // Increment moves
    moves_W++;
    if (moves_W == 9) {
        on_Clear_clicked();
        draw_W(this);
    }

    // Handle random player
    if (ui->Player2_name->text() == "Random Player") {
        makeRandomMove();
    }
    // Handle AI player
    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalculatedMove();
    }
}


void Word::on_cell_00_clicked()
{
    handle_cell(0 , 0 , ui->enabled_chars->currentText().toUtf8()[0]);
}


void Word::on_cell_01_clicked()
{
    handle_cell(0 , 1 , ui->enabled_chars->currentText().toUtf8()[0]);
}


void Word::on_cell_02_clicked()
{
    handle_cell(0 , 2 , ui->enabled_chars->currentText().toUtf8()[0]);
}


void Word::on_cell_10_clicked()
{
    handle_cell(1 , 0 , ui->enabled_chars->currentText().toUtf8()[0]);
}


void Word::on_cell_11_clicked()
{
    handle_cell(1 , 1 , ui->enabled_chars->currentText().toUtf8()[0]);
}


void Word::on_cell_12_clicked()
{
    handle_cell(1 , 2 , ui->enabled_chars->currentText().toUtf8()[0]);
}


void Word::on_cell_20_clicked()
{
    handle_cell(2 , 0 , ui->enabled_chars->currentText().toUtf8()[0]);
}


void Word::on_cell_21_clicked()
{
    handle_cell(2 , 1 , ui->enabled_chars->currentText().toUtf8()[0]);
}


void Word::on_cell_22_clicked()
{
    handle_cell(2 , 2 , ui->enabled_chars->currentText().toUtf8()[0]);
}


void Word::on_Clear_clicked()
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
            B_W->update_board(i , j , 0);
        }
    }
    moves_W = 0;
    clicked_W = vector<int>(9);
    delete B_W;
    B_W = new Word_TIC_TAC_TOE_Board<char>;
}

void Word::makeCalculatedMove()
{
    // check if i can win in the next move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (char k = 'A'; k <= 'Z'; ++k) {
                if(!B_W->update_board(i , j , k))
                    continue;
                if(B_W->is_win())
                {
                    moves_W++;
                    QString cellName = "cell_" + QString::number(i) + QString::number(j);
                    QPushButton *cellButton = findChild<QPushButton*>(cellName);
                    if (cellButton) {
                        cellButton->setText(QString(k));
                        cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: blue ; font-size: 28pt; font-weight: bold;");
                    }
                    clicked_W[i * 3 + j]++;
                    ui->p2_score->setText(QString::number(++p2_score_W));
                    win_W(this, ui->Player2_name->text());
                    this->on_Clear_clicked();
                    return;
                }
                B_W->update_board(i , j , 0);
            }
        }
    }

    // if no good move make a random move
    makeRandomMove();
}

