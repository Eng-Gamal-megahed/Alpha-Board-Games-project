#include "inverse.h"
#include "ui_inverse.h"
#include "mainwindow.h"
#include <iomanip>

template <typename T>
Inverse_Board<T>::Inverse_Board() {
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
bool Inverse_Board<T>::update_board(int x, int y, T mark) {
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
void Inverse_Board<T>::display_board() {
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
bool Inverse_Board<T>::is_win() {
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
bool Inverse_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Inverse_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

Inverse::Inverse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inverse)
{
    ui->setupUi(this);
    ui->Player1_name->setAlignment(Qt::AlignCenter);
    ui->p1_score->setAlignment(Qt::AlignCenter);
    ui->p2_score->setAlignment(Qt::AlignCenter);
    ui->Player2_name->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
}

Inverse::~Inverse()
{
    delete ui;
}

void Inverse::setNames(QString p1 , QString p2)
{
    ui->Player1_name->setText(p1);
    ui->Player2_name->setText(p2);
}

void Inverse::on_Back_clicked()
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

Board<char>* B_I = new Inverse_Board<char>;
int moves_I = 0 , p1_score_I = 0 , p2_score_I = 0;
vector<int>clicked_I(9);

void draw_I(QWidget *parent) {
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

void win_I(QWidget *parent , QString winner)
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
void Inverse::makeRandomMove() {
    int x, y;
    do {
        // Generate random row and column between 0 and 2
        x = QRandomGenerator::global()->bounded(0, 3);
        y = QRandomGenerator::global()->bounded(0, 3);
    } while (clicked_I[x * 3 + y]); // Repeat until an empty cell is found

    // Update the board and UI with Player 2's move
    QString cellName = QString("cell_%1%2").arg(x).arg(y);
    QPushButton* button = this->findChild<QPushButton*>(cellName);
    if (button) {
        button->setText("O");
        button->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
        B_I->update_board(x, y, 'O');
        clicked_I[x * 3 + y] = 1;
        moves_I++;
    }

    // Check for win or draw after the move
    if (B_I->is_win()) {
        ui->p1_score->setText(QString::number(++p1_score_I));
        win_I(this, ui->Player1_name->text());
        this->on_Clear_clicked();
    } else if (moves_I == 9) {
        draw_I(this); return;
        this->on_Clear_clicked();
    }
}

void Inverse::handle_cell(int x , int y)
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

    if (clicked_I[x * 3 + y]++) {
        return; // Ignore if the cell is already clicked
    }

    QString mark;
    QString color;

    // Determine which player's turn it is
    if (moves_I & 1) {
        mark = "O";
        color = "red";
    } else {
        mark = "X";
        color = "blue";
    }

    // Update the board and the corresponding button
    QString cellName = "cell_" + QString::number(x) + QString::number(y);
    QPushButton *cellButton = findChild<QPushButton*>(cellName);
    if (cellButton) {
        cellButton->setText(mark);
        cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: " + color + "; font-size: 28pt; font-weight: bold;");
    }

    B_I->update_board(x , y , mark.toStdString()[0]);

    // Check for win
    if (B_I->is_win()) {
        if (moves_I & 1) {
            ui->p1_score->setText(QString::number(++p1_score_I));
        } else {
            ui->p2_score->setText(QString::number(++p2_score_I));
        }
        win_I(this, (moves_I & 1) ? ui->Player1_name->text() : ui->Player2_name->text());
        on_Clear_clicked();
        return;
    }

    // Increment moves
    moves_I++;
    if (moves_I == 9) {
        on_Clear_clicked();
        draw_I(this);
        return;
    }

    // Handle random player logic
    if (ui->Player2_name->text() == "Random Player") {
        makeRandomMove();
    }

    // Handle AI player logic
    if (ui->Player2_name->text() == "AI Player") {
        makeCalclutedMove();
    }
}

void Inverse::on_cell_00_clicked()
{
    handle_cell(0 , 0);
}


void Inverse::on_cell_01_clicked()
{
    handle_cell(0 , 1);
}


void Inverse::on_cell_02_clicked()
{
    handle_cell(0 , 2);
}


void Inverse::on_cell_10_clicked()
{
    handle_cell(1 , 0);
}


void Inverse::on_cell_11_clicked()
{
    handle_cell(1 , 1);
}


void Inverse::on_cell_12_clicked()
{
    handle_cell(1 , 2);
}


void Inverse::on_cell_20_clicked()
{
    handle_cell(2 , 0);
}


void Inverse::on_cell_21_clicked()
{
    handle_cell(2 , 1);
}


void Inverse::on_cell_22_clicked()
{
    handle_cell(2 , 2);
}


void Inverse::on_Clear_clicked()
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
            B_I->update_board(i , j , 0);
        }
    }
    clicked_I = vector<int>(9);
    moves_I = 0;
}

void Inverse::makeCalclutedMove()
{
    // check if i can not lose in the next move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(!B_I->update_board(i , j , 'O'))
                continue;
            if(!B_I->is_win())
            {
                moves_I++;
                QString cellName = "cell_" + QString::number(i) + QString::number(j);
                QPushButton *cellButton = findChild<QPushButton*>(cellName);
                if (cellButton) {
                    cellButton->setText("O");
                    cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: red ; font-size: 28pt; font-weight: bold;");
                }
                clicked_I[i * 3 + j]++;
                return;
            }
            B_I->update_board(i , j , 0);
        }
    }

    // if no good move make a random move
    makeRandomMove();
}

