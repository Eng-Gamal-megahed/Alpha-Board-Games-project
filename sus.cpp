#include "sus.h"
#include "ui_sus.h"
#include "mainwindow.h"
#include <iomanip>
template <typename T>
SUS_Board<T>::SUS_Board() {
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
bool SUS_Board<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = mark;
        }

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void SUS_Board<T>::display_board() {
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
bool SUS_Board<T>::is_win() {
    int cnt = 0;
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[0][i] == 'S' && this->board[1][i] == 'U' && this->board[2][i] == 'S')) {
            cnt++;
        }
    }

    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == 'S' && this->board[i][1] == 'U' && this->board[i][2] == 'S')) {
            cnt++;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == 'S' && this->board[1][1] == 'U' &&  this->board[2][2] == 'S')) {
        cnt++;
    }
    if ((this->board[0][2] == 'S' && this->board[1][1] == 'U' &&  this->board[2][0] == 'S')) {
        cnt++;
    }

    if(cnt > p1_chains + p2_chains)
    {
        if(this->n_moves & 1)
        {
            p1_chains += cnt - (p1_chains + p2_chains);
        }
        else
        {
            p2_chains += cnt - (p1_chains + p2_chains);
        }
    }

    return (this->n_moves == 9 && p1_chains != p2_chains);
}

// Return true if 9 moves_B are done and no winner
template <typename T>
bool SUS_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool SUS_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

SUS::SUS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SUS)
{
    ui->setupUi(this);
    ui->Player1_name->setAlignment(Qt::AlignCenter);
    ui->p1_score->setAlignment(Qt::AlignCenter);
    ui->p2_score->setAlignment(Qt::AlignCenter);
    ui->Player2_name->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
}

SUS::~SUS()
{
    delete ui;
}

void SUS::setNames(QString p1 , QString p2)
{
    ui->Player1_name->setText(p1);
    ui->Player2_name->setText(p2);
}
SUS_Board<char>* B_S = new SUS_Board<char>;
int moves_S = 0 , p1_score_S = 0 , p2_score_S = 0 ;
vector<int>clicked_S(9);

void draw_S(QWidget *parent) {
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

void win_S(QWidget *parent , QString winner)
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

void SUS::handle_cell(int x , int y)
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

    if (clicked_S[x * 3 + y]++) {
        return; // Ignore if the cell is already clicked
    }

    QString mark;
    QString color = "blue";

    // Determine which player's turn it is
    if (moves_S & 1) {
        mark = "U";
    } else {
        mark = "S";
    }

    // Update the board and the corresponding button
    QString cellName = "cell_" + QString::number(x) + QString::number(y);
    QPushButton *cellButton = findChild<QPushButton*>(cellName);
    if (cellButton) {
        cellButton->setText(mark);
        cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: " + color + "; font-size: 28pt; font-weight: bold;");
    }

    B_S->update_board(x , y , mark.toStdString()[0]);
    B_S->is_win();
    moves_S++;
    if (moves_S == 9) {
        if(B_S->p1_chains != B_S->p2_chains)
        {
            if(B_S->p1_chains > B_S->p2_chains)
            {
                win_S(this , ui->Player1_name->text());
                ui->p1_score->setText(QString::number(++p1_score_S));
            }
            else
            {
                win_S(this , ui->Player2_name->text());
                ui->p2_score->setText(QString::number(++p2_score_S));
            }
            on_Clear_clicked();
            return;
        }
        else
        {
            on_Clear_clicked();
            draw_S(this);
            return;
        }

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

void SUS::on_Back_clicked()
{
    on_Clear_clicked();
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

#include <QRandomGenerator>

// Function to make a random move for Player 2
void SUS::makeRandomMove() {
    int x, y;
    do {
        // Generate random row and column between 0 and 2
        x = QRandomGenerator::global()->bounded(0, 3);
        y = QRandomGenerator::global()->bounded(0, 3);
    } while (clicked_S[x * 3 + y]); // Repeat until an empty cell is found
    // Update the board and UI with Player 2's move
    QString cellName = QString("cell_%1%2").arg(x).arg(y);
    QPushButton* button = this->findChild<QPushButton*>(cellName);
    if (button) {
        button->setText("U");
        button->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
        B_S->update_board(x, y, 'U');
        B_S->is_win();
        clicked_S[x * 3 + y] = 1;
        moves_S++;
    }
}
void SUS::on_cell_00_clicked()
{
    handle_cell(0 , 0);
}


void SUS::on_cell_01_clicked()
{
    handle_cell(0 , 1);
}


void SUS::on_cell_02_clicked()
{
    handle_cell(0 , 2);
}


void SUS::on_cell_10_clicked()
{
    handle_cell(1 , 0);
}


void SUS::on_cell_11_clicked()
{
    handle_cell(1 , 1);
}


void SUS::on_cell_12_clicked()
{
    handle_cell(1 , 2);
}


void SUS::on_cell_20_clicked()
{
    handle_cell(2 , 0);
}


void SUS::on_cell_21_clicked()
{
    handle_cell(2 , 1);
}


void SUS::on_cell_22_clicked()
{
    handle_cell(2 , 2);
}


void SUS::on_Clear_clicked()
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
            B_S->update_board(i , j , 0);
        }
    }
    B_S->p1_chains = B_S->p2_chains = 0;
    clicked_S = vector<int>(9);
    moves_S = 0;
}

void SUS::makeCalculatedMove()
{
    int last_chains = B_S->p1_chains + B_S->p2_chains;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(!B_S->update_board(i , j , 'U'))
                continue;
            B_S->is_win();
            if(B_S->p2_chains + B_S->p1_chains > last_chains)
            {
                moves_S++;
                QString cellName = "cell_" + QString::number(i) + QString::number(j);
                QPushButton *cellButton = findChild<QPushButton*>(cellName);
                if (cellButton) {
                    cellButton->setText("U");
                    cellButton->setStyleSheet("background-color: rgb(2, 26, 26); color: blue; font-size: 28pt; font-weight: bold;");
                }
                clicked_S[i * 3 + j]++;
                return;
            }
            B_S->update_board(i , j , 0);
        }
    }

    last_chains = B_S->p1_chains + B_S->p2_chains;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(!B_S->update_board(i , j , 'S'))
                continue;
            B_S->is_win();
            if(B_S->p2_chains + B_S->p1_chains > last_chains)
            {
                B_S->p2_chains -= (B_S->p2_chains + B_S->p1_chains - last_chains);
                moves_S++;
                QString cellName = "cell_" + QString::number(i) + QString::number(j);
                QPushButton *cellButton = findChild<QPushButton*>(cellName);
                if (cellButton) {
                    cellButton->setText("U");
                    cellButton->setStyleSheet("background-color: rgb(2, 26, 26); color: blue; font-size: 28pt; font-weight: bold;");
                }
                clicked_S[i * 3 + j]++;
                B_S->update_board(i , j , 0);
                B_S->update_board(i , j , 'U');
                return;
            }
            B_S->update_board(i , j , 0);
        }
    }

    makeRandomMove();
}

