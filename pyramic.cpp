#include "pyramic.h"
#include "ui_pyramic.h"
#include "mainwindow.h"
#include <QMessageBox>


template <typename T>
P_TIC_TAC_TOE<T>::P_TIC_TAC_TOE() {
    this->rows = 3;
    this->columns = 5;
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
bool P_TIC_TAC_TOE<T>::update_board(int x, int y, T mark) {
    if ((x == 0 && y != 2) || (x == 1 && (y == 0 || y == 4)))
    {
        return false;
    }
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

template <typename T>
void P_TIC_TAC_TOE<T>::display_board() {
    cout << "\n----------------------------------------------";
    for (int i = 0; i < this->rows; i++)
    {
        cout << "\n|";
        for (int j = 0; j < this->columns; j++)
        {
            if ((i == 0 && j != 2) || (i == 1 && (j == 0 || j == 4)))
            {
                cout << string(7, ' ') << " |";
                continue;
            }
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n----------------------------------------------";
    }
    cout << endl;
}
template <typename T>
bool P_TIC_TAC_TOE<T>::is_win() {
    /// check columns
    if(this->board[0][2] == this->board[1][2] && this->board[1][2] == this->board[2][2] && this->board[0][2] != 0)
    {
        return true;
    }
    /// check rows
    if((this->board[1][1] == this->board[1][2] && this->board[1][2] == this->board[1][3] && this->board[1][2] != 0) ||
        (this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2] && this->board[2][2] != 0) ||
        (this->board[2][1] == this->board[2][2] && this->board[2][2] == this->board[2][3] && this->board[2][2] != 0) ||
        (this->board[2][2] == this->board[2][3] && this->board[2][3] == this->board[2][4] && this->board[2][2] != 0))
    {
        return true;
    }

    /// diagonals
    if((this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0) ||
        (this->board[0][2] == this->board[1][3] && this->board[1][3] == this->board[2][4] && this->board[0][2]) != 0)
    {
        return true;
    }

    return false;
}


template <typename T>
bool P_TIC_TAC_TOE<T>::is_draw() {
    return this->n_moves == 9;
}

template <typename T>
bool P_TIC_TAC_TOE<T>::game_is_over() {
    return this->is_draw() || this->is_win();
}

PYRAMIC::PYRAMIC(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PYRAMIC)
{
    ui->setupUi(this);
    ui->Player1_name->setAlignment(Qt::AlignCenter);
    ui->p1_score->setAlignment(Qt::AlignCenter);
    ui->p2_score->setAlignment(Qt::AlignCenter);
    ui->Player2_name->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
}

PYRAMIC::~PYRAMIC()
{
    delete ui;
}

void PYRAMIC::setNames(QString p1 , QString p2)
{
    ui->Player1_name->setText(p1);
    ui->Player2_name->setText(p2);
}

void PYRAMIC::on_Back_clicked()
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

Board<char>* B_P = new P_TIC_TAC_TOE<char>();
int moves_P = 0 , p1_score_P = 0 , p2_score_P = 0;
vector<int>clicked_P(15);


void draw_P(QWidget *parent) {
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

void win_P(QWidget *parent , QString winner)
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



void PYRAMIC::handle_cell(int x , int y)
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

    if (clicked_P[x * 5 + y]++) {
        return; // Ignore if the cell is already clicked
    }

    QString mark;
    QString color;

    // Determine which player's turn it is
    if (moves_P & 1) {
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

    // Update the board logic
    if (!B_P->update_board(x, y, mark.toUtf8()[0])) {
        return; // If update fails (e.g., invalid move), exit
    }

    // Check for win
    if (B_P->is_win()) {
        if (moves_P & 1) {
            ui->p2_score->setText(QString::number(++p2_score_P));
        } else {
            ui->p1_score->setText(QString::number(++p1_score_P));
        }
        win_P(this, (moves_P & 1) ? ui->Player2_name->text() : ui->Player1_name->text());
        on_Clear_clicked();
        return;
    }

    // Increment moves
    moves_P++;
    if (moves_P == 9) {
        on_Clear_clicked();
        draw_P(this);
        return;
    }

    // Handle random player logic
    if (ui->Player2_name->text() == "Random Player") {
        makeRandomMove();
    }

    // Handle AI player logic
    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalclutedMove();
    }
}



void PYRAMIC::on_Clear_clicked()
{
    ui->cell_02->setText("");
    ui->cell_11->setText("");
    ui->cell_12->setText("");
    ui->cell_13->setText("");
    ui->cell_20->setText("");
    ui->cell_21->setText("");
    ui->cell_22->setText("");
    ui->cell_23->setText("");
    ui->cell_24->setText("");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            B_P->update_board(i , j , 0);
        }
    }
    clicked_P = vector<int>(15);
    moves_P = 0;
}

void PYRAMIC::makeRandomMove()
{
    int x = rand() % 3;
    int y = rand() % 5;
    while (!B_P->update_board(x , y , 'O')) {
        x = rand() % 3;
        y = rand() % 5;
    }
    clicked_P[x * 5 + y]++;
    QString cellName = "cell_" + QString::number(x) + QString::number(y);
    QPushButton *cellButton = findChild<QPushButton*>(cellName);
    if (cellButton) {
        cellButton->setText("O");
        cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color:red; font-size: 28pt; font-weight: bold;");
    }
    if (B_P->is_win()) {
        if (moves_P & 1) {
            ui->p2_score->setText(QString::number(++p2_score_P));
        } else {
            ui->p1_score->setText(QString::number(++p1_score_P));
        }
        win_P(this, (moves_P & 1) ? ui->Player2_name->text() : ui->Player1_name->text());
        on_Clear_clicked();
        return;
    }

    // Increment moves
    moves_P++;
    if (moves_P == 9) {
        on_Clear_clicked();
        draw_P(this);
    }
}





void PYRAMIC::on_cell_02_clicked()
{
    handle_cell(0 , 2);
}


void PYRAMIC::on_cell_11_clicked()
{
    handle_cell(1 , 1);
}


void PYRAMIC::on_cell_12_clicked()
{
    handle_cell(1 , 2);
}


void PYRAMIC::on_cell_13_clicked()
{
    handle_cell(1 , 3);
}


void PYRAMIC::on_cell_20_clicked()
{
    handle_cell(2 , 0);
}


void PYRAMIC::on_cell_21_clicked()
{
    handle_cell(2 , 1);
}


void PYRAMIC::on_cell_22_clicked()
{
    handle_cell(2 , 2);
}


void PYRAMIC::on_cell_23_clicked()
{
    handle_cell(2 , 3);
}


void PYRAMIC::on_cell_24_clicked()
{
    handle_cell(2 , 4);
}

void PYRAMIC::makeCalclutedMove()
{
    // check if i can win in the next move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(!B_P->update_board(i , j , 'O'))
                continue;
            if(B_P->is_win())
            {
                moves_P++;
                QString cellName = "cell_" + QString::number(i) + QString::number(j);
                QPushButton *cellButton = findChild<QPushButton*>(cellName);
                if (cellButton) {
                    cellButton->setText("O");
                    cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: red ; font-size: 28pt; font-weight: bold;");
                }
                clicked_P[i * 5 + j]++;
                ui->p2_score->setText(QString::number(++p2_score_P));
                win_P(this, ui->Player2_name->text());
                this->on_Clear_clicked();
                return;
            }
            B_P->update_board(i , j , 0);
        }
    }

    // check if the oppennet can win in the next move

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(!B_P->update_board(i , j , 'X'))
                continue;
            if(B_P->is_win())
            {
                B_P->update_board(i , j , 0);
                B_P->update_board(i , j , 'O');
                moves_P++;
                QString cellName = "cell_" + QString::number(i) + QString::number(j);
                QPushButton *cellButton = findChild<QPushButton*>(cellName);
                if (cellButton) {
                    cellButton->setText("O");
                    cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: red ; font-size: 28pt; font-weight: bold;");
                }
                clicked_P[i * 5 + j]++;
                return;
            }
            B_P->update_board(i , j , 0);
        }
    }

    // if no good move make a random move
    makeRandomMove();
}


