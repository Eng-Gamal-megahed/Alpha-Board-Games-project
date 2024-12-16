#include "numaric.h"
#include "ui_numaric.h"
#include "mainwindow.h"
#include <algorithm>
#include <iomanip>

template <typename T>
NUM_TIC_TAC_TOE_Board<T>::NUM_TIC_TAC_TOE_Board() {
    this->rows = this->columns = 3;
    this->board = new int*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new int[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool NUM_TIC_TAC_TOE_Board<T>::update_board(int x, int y, T mark) {
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
void NUM_TIC_TAC_TOE_Board<T>::display_board() {
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
bool NUM_TIC_TAC_TOE_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; ++i) {
        // Check row `i`
        if (this->board[i][0] && this->board[i][1] && this->board[i][2] &&
            this->board[i][0] + this->board[i][1] + this->board[i][2] == 15) {
            return true;
        }

        // Check column `i`
        if (this->board[0][i] && this->board[1][i] && this->board[2][i] &&
            this->board[0][i] + this->board[1][i] + this->board[2][i] == 15) {
            return true;
        }
    }

    // Check main diagonal
    if (this->board[0][0] && this->board[1][1] && this->board[2][2] &&
        this->board[0][0] + this->board[1][1] + this->board[2][2] == 15) {
        return true;
    }

    // Check anti-diagonal
    if (this->board[0][2] && this->board[1][1] && this->board[2][0] &&
        this->board[0][2] + this->board[1][1] + this->board[2][0] == 15) {
        return true;
    }

    return false;
}


// Return true if 9 moves are done and no winner
template <typename T>
bool NUM_TIC_TAC_TOE_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool NUM_TIC_TAC_TOE_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

void draw_N(QWidget *parent) {
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

void win_N(QWidget *parent , QString winner)
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

Numaric::Numaric(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Numaric)
{
    ui->setupUi(this);
    ui->enabled_nubers->addItem("1");
    ui->enabled_nubers->addItem("3");
    ui->enabled_nubers->addItem("5");
    ui->enabled_nubers->addItem("7");
    ui->enabled_nubers->addItem("9");
    ui->enabled_nubers->setCurrentIndex(0);
    ui->Player1_name->setAlignment(Qt::AlignCenter);
    ui->p1_score->setAlignment(Qt::AlignCenter);
    ui->p2_score->setAlignment(Qt::AlignCenter);
    ui->Player2_name->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
}

Numaric::~Numaric()
{
    delete ui;
}

void Numaric::setNames(QString p1 , QString p2)
{
    ui->Player1_name->setText(p1);
    ui->Player2_name->setText(p2);
}

void Numaric::on_Back_clicked()
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



int moves_N = 0 , p1_score_N = 0 , p2_score_N = 0;
vector<int>clicked_N(9 , 0) , p1 = {1 , 3 , 5 , 7 , 9} , p2 = {2 , 4 , 6 , 8};
Board<int>* B_N = new NUM_TIC_TAC_TOE_Board<int>;


void Numaric::handle_cell(int x , int y , int num)
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

    if (clicked_N[x * 3 + y]++) {
        return; // Ignore if the cell is already clicked
    }

    QString mark = QString::number(num);
    QString color = "blue";
    if (moves_N & 1) {
        p2.erase(::find(p2.begin(), p2.end(), num));
    } else {
        p1.erase(::find(p1.begin(), p1.end(), num));
    }
    // Update the board and the corresponding button
    QString cellName = "cell_" + QString::number(x) + QString::number(y);
    QPushButton *cellButton = findChild<QPushButton*>(cellName);
    if (cellButton) {
        cellButton->setText(mark);
        cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: " + color + "; font-size: 28pt; font-weight: bold;");
    }

    // Update the board logic
    B_N->update_board(x , y , num);

    // Check for win
    if (B_N->is_win()) {
        if (moves_N & 1) {
            ui->p2_score->setText(QString::number(++p2_score_N));
        } else {
            ui->p1_score->setText(QString::number(++p1_score_N));
        }
        win_N(this, (moves_N & 1) ? ui->Player2_name->text() : ui->Player1_name->text());
        on_Clear_clicked();
        return;
    }

    // Increment moves
    moves_N++;
    if (p1.empty() && p2.empty()) {
        on_Clear_clicked();
        draw_N(this);
        return;
    }

    ui->enabled_nubers->clear();
    if(moves_N & 1)
    {
        for (int i = 0; i < (int)p2.size(); ++i) {
            ui->enabled_nubers->addItem(QString::number(p2[i]));
        }
    }
    else
    {
        for (int i = 0; i < (int)p1.size(); ++i) {
            ui->enabled_nubers->addItem(QString::number(p1[i]));
        }
    }

    // Handle random player logic if needed
    if (ui->Player2_name->text() == "Random Player") {
        makeRandomMove();
        ui->enabled_nubers->clear();
            for (int i = 0; i < p1.size(); ++i) {
                ui->enabled_nubers->addItem(QString::number(p1[i]));
            }
    }

    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalculatedMove();
        ui->enabled_nubers->clear();
        for (int i = 0; i < p1.size(); ++i) {
            ui->enabled_nubers->addItem(QString::number(p1[i]));
        }
    }
}


void Numaric::on_Clear_clicked()
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
            B_N->update_board(i , j , 0);
        }
    }
    moves_N = 0;
    clicked_N = vector<int>(9);
    p1 = {1 , 3 , 5 , 7 , 9};
    p2 = {2 , 4 , 6 , 8};
    delete B_N;
    B_N = new NUM_TIC_TAC_TOE_Board<int>;
    ui->enabled_nubers->clear();
    for (int i = 0; i < p1.size(); ++i) {
        ui->enabled_nubers->addItem(QString::number(p1[i]));
    }
}


void Numaric::on_cell_00_clicked()
{
    handle_cell(0 , 0 , ui->enabled_nubers->currentText().toInt());
}


void Numaric::on_cell_01_clicked()
{
    handle_cell(0 , 1 , ui->enabled_nubers->currentText().toInt());
}


void Numaric::on_cell_02_clicked()
{
    handle_cell(0 , 2 , ui->enabled_nubers->currentText().toInt());
}


void Numaric::on_cell_10_clicked()
{
    handle_cell(1 , 0 , ui->enabled_nubers->currentText().toInt());
}


void Numaric::on_cell_11_clicked()
{
    handle_cell(1 , 1 , ui->enabled_nubers->currentText().toInt());
}


void Numaric::on_cell_12_clicked()
{
    handle_cell(1 , 2 , ui->enabled_nubers->currentText().toInt());
}


void Numaric::on_cell_20_clicked()
{
    handle_cell(2 , 0 , ui->enabled_nubers->currentText().toInt());
}


void Numaric::on_cell_21_clicked()
{
    handle_cell(2 , 1 , ui->enabled_nubers->currentText().toInt());
}


void Numaric::on_cell_22_clicked()
{
    handle_cell(2 , 2 , ui->enabled_nubers->currentText().toInt());
}

void Numaric::makeRandomMove()
{
    int x = rand() % 3;
    int y = rand() % 5;
    int idx = rand() % p2.size();
    while (!B_N->update_board(x , y , p2[idx])) {
        x = rand() % 3;
        y = rand() % 5;
    }
    clicked_N[x * 3 + y]++;
    QString cellName = "cell_" + QString::number(x) + QString::number(y);
    QPushButton *cellButton = findChild<QPushButton*>(cellName);
    if (cellButton) {
        cellButton->setText(QString::number(p2[idx]));
        cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color:blue; font-size: 28pt; font-weight: bold;");
    }
    moves_N++;
    if (p1.empty() && p2.empty()) {
        on_Clear_clicked();
        draw_N(this);
    }
    p2.erase(::find(p2.begin(), p2.end(), p2[idx]));
    if (B_N->is_win()) {
        ui->p2_score->setText(QString::number(++p2_score_N));
        win_N(this, ui->Player2_name->text());
        on_Clear_clicked();
        return;
}
}

void Numaric::makeCalculatedMove()
{
    // check if i can win in the next move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < p2.size(); ++k) {
                if(!B_N->update_board(i , j , p2[k]))
                    continue;
                if(B_N->is_win())
                {
                    moves_N++;
                    QString cellName = "cell_" + QString::number(i) + QString::number(j);
                    QPushButton *cellButton = findChild<QPushButton*>(cellName);
                    if (cellButton) {
                        cellButton->setText(QString::number(p2[k]));
                        cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: blue ; font-size: 28pt; font-weight: bold;");
                    }
                    clicked_N[i * 3 + j]++;
                    p2.erase(p2.begin() + k);
                    ui->p2_score->setText(QString::number(++p2_score_N));
                    win_N(this, ui->Player2_name->text());
                    this->on_Clear_clicked();
                    return;
                }
                B_N->update_board(i , j , 0);
            }
        }
    }

    // check if the oppennet can win in the next move

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < p1.size(); ++k) {
                if(!B_N->update_board(i , j , p1[k]))
                    continue;
                if(B_N->is_win())
                {
                    moves_N++;
                    B_N->update_board(i , j , 0);
                    B_N->update_board(i , j , p2[0]);
                    QString cellName = "cell_" + QString::number(i) + QString::number(j);
                    QPushButton *cellButton = findChild<QPushButton*>(cellName);
                    if (cellButton) {
                        cellButton->setText(QString::number(p2[0]));
                        cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: blue ; font-size: 28pt; font-weight: bold;");
                    }
                    clicked_N[i * 3 + j]++;
                    p2.erase(p2.begin());
                    return;
                }
                B_N->update_board(i , j , 0);
            }
        }
    }

    // if no good move make a random move
    makeRandomMove();
}

