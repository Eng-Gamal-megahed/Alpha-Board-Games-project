#include "fourxfour.h"
#include "ui_fourxfour.h"
#include "mainwindow.h"

template <typename T>
FXF_TIC_TAC_TOE<T>::FXF_TIC_TAC_TOE() {
    this->rows = 4;
    this->columns = 4;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;

    for (int i = 0; i < 4; ++i) {
        this->update_board(0 , i , (i & 1)? 'X' : 'O');
        this->update_board(3 , i , (i & 1)? 'O' : 'X');
    }
}

template <typename T>
bool FXF_TIC_TAC_TOE<T>::update_board(int x, int y, T mark) {
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

template <typename T>
void FXF_TIC_TAC_TOE<T>::display_board() {
    cout << "\n----------------------------------------------";
    for (int i = 0; i < this->rows; i++)
    {
        cout << "\n|";
        for (int j = 0; j < this->columns; j++)
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n----------------------------------------------";
    }
    cout << endl;
}


template <typename T>
bool FXF_TIC_TAC_TOE<T>::is_win() {
    /// Check rows for a chain of 3
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j <= this->columns - 3; ++j) { // Adjust for 3 consecutive marks
            bool chain = this->board[i][j] == this->board[i][j + 1];
            for (int k = j + 1; k < j + 3 && chain; k++) {
                chain &= this->board[i][k - 1] == this->board[i][k];
            }
            if (chain && this->board[i][j] != 0) {
                return true;
            }
        }
    }

    /// Check columns for a chain of 3
    for (int i = 0; i < this->columns; ++i) {
        for (int j = 0; j <= this->rows - 3; ++j) { // Adjust for 3 consecutive marks
            bool chain = this->board[j][i] == this->board[j + 1][i];
            for (int k = j + 1; k < j + 3 && chain; k++) {
                chain &= this->board[k - 1][i] == this->board[k][i];
            }
            if (chain && this->board[j][i] != 0) {
                return true;
            }
        }
    }

    /// Check diagonals (top-left to bottom-right) for a chain of 3
    for (int i = 0; i <= this->rows - 3; ++i) {
        for (int j = 0; j <= this->columns - 3; ++j) {
            bool chain = this->board[i][j] == this->board[i + 1][j + 1];
            for (int k = 1; k < 3 && chain; k++) {
                chain &= this->board[i + k - 1][j + k - 1] == this->board[i + k][j + k];
            }
            if (chain && this->board[i][j] != 0) {
                return true;
            }
        }
    }

    /// Check diagonals (bottom-left to top-right) for a chain of 3
    for (int i = 2; i < this->rows; ++i) {
        for (int j = 0; j <= this->columns - 3; ++j) {
            bool chain = this->board[i][j] == this->board[i - 1][j + 1];
            for (int k = 1; k < 3 && chain; k++) {
                chain &= this->board[i - k + 1][j + k - 1] == this->board[i - k][j + k];
            }
            if (chain && this->board[i][j] != 0) {
                return true;
            }
        }
    }

    return false;
}

template <typename T>
bool FXF_TIC_TAC_TOE<T>::is_draw() {
    return this->n_moves == 25;
}

template <typename T>
bool FXF_TIC_TAC_TOE<T>::game_is_over() {
    return this->is_win() || this->is_win();
}

vector<int>is_empty_cell(16 , 1);

FourXFour::FourXFour(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FourXFour)
{
    ui->setupUi(this);
    ui->Player1_name->setAlignment(Qt::AlignCenter);
    ui->p1_score->setAlignment(Qt::AlignCenter);
    ui->p2_score->setAlignment(Qt::AlignCenter);
    ui->Player2_name->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
    for (int i = 0; i < 4; ++i) {
        is_empty_cell[i] = 0;
        is_empty_cell[15 - i] = 0;
    }
}

FourXFour::~FourXFour()
{
    delete ui;
}

void FourXFour::setNames(QString p1 , QString p2)
{
    ui->Player1_name->setText(p1);
    ui->Player2_name->setText(p2);
}

void FourXFour::on_Back_clicked()
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

Board<char>* B_F = new FXF_TIC_TAC_TOE<char>;
int moves_F = 0 , p1_score_F = 0 , p2_score_F = 0;
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

void draw_F(QWidget *parent) {
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

void win_F(QWidget *parent , QString winner)
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
void FourXFour::makeRandomMove() {
    srand(time(0));
    int x = rand() % 4;
    int y = rand() % 4;
    QString cellName = "cell_" + QString::number(x) + QString::number(y);
    QPushButton *cellButton = findChild<QPushButton*>(cellName);
    while(is_empty_cell[x * 4 + y] || cellButton->text() != "O")
    {
        x = rand() % 4;
        y = rand() % 4;
        cellName = "cell_" + QString::number(x) + QString::number(y);
        cellButton = findChild<QPushButton*>(cellName);
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i] , ny = y + dy[i];
        if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && is_empty_cell[nx * 4 + ny])
        {
            QString n_cellName = "cell_" + QString::number(nx) + QString::number(ny);
            QPushButton *n_cellButton = findChild<QPushButton*>(n_cellName);
            cellButton->setText("");
            n_cellButton->setText("O");
            n_cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
            is_empty_cell[x * 4 + y] = 1;
            is_empty_cell[nx * 4 + ny] = 0;
            B_F->update_board(x, y, 0);
            B_F->update_board(nx, ny, 'O');
            moves_F++;
            if(B_F->is_win())
            {
                win_F(this, ui->Player2_name->text());
                on_Clear_clicked();
            }
            return;
        }
    }
    makeRandomMove();
    return;
}



void FourXFour::handle_cell(int x , int y)
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

    int shift_idx = ui->comboBox->currentIndex();
    int nx = x + dx[shift_idx] , ny = y + dy[shift_idx];
    if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && is_empty_cell[nx * 4 + ny] && !is_empty_cell[x * 4 + y])
    {
        QString mark;
        QString color;

        // Update the board and the corresponding button
        QString n_cellName = "cell_" + QString::number(nx) + QString::number(ny);
        QPushButton *n_cellButton = findChild<QPushButton*>(n_cellName);
        QString cellName = "cell_" + QString::number(x) + QString::number(y);
        QPushButton *cellButton = findChild<QPushButton*>(cellName);
        mark = cellButton->text();
        if((mark == "X" && (moves_F & 1)) || (mark == "O" && !(moves_F & 1)))
        {
            return;
        }
        is_empty_cell[nx * 4 + ny] = 0;
        is_empty_cell[x * 4 + y] = 1;
        color = (mark == "X" ? "blue" : "red");
            cellButton->setText("");
        B_F->update_board(x , y , 0);
            n_cellButton->setText(mark);
            n_cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: " + color + "; font-size: 28pt; font-weight: bold;");

        if (!B_F->update_board(nx, ny, mark.toUtf8()[0])) {
            return;
        }
        moves_F++;
        if(B_F->is_win())
        {
            if (moves_F & 1) {
                ui->p1_score->setText(QString::number(++p1_score_F));
            } else {
                ui->p2_score->setText(QString::number(++p2_score_F));
            }
            win_F(this, (moves_F & 1) ? ui->Player1_name->text() : ui->Player2_name->text());
            on_Clear_clicked();
            return;
        }
        // Handle random player logic
        if (ui->Player2_name->text() == "Random Player") {
            makeRandomMove();
        }

        // Handle AI player logic

        if(ui->Player2_name->text() == "AI Player")
        {
            makeCalculatedMove();
        }
    }
}


void FourXFour::on_cell_00_clicked()
{
    handle_cell(0 , 0);
}


void FourXFour::on_cell_01_clicked()
{
    handle_cell(0 , 1);
}


void FourXFour::on_cell_02_clicked()
{
    handle_cell(0 , 2);
}


void FourXFour::on_cell_03_clicked()
{
    handle_cell(0 , 3);

}


void FourXFour::on_cell_10_clicked()
{
    handle_cell(1 , 0);
}


void FourXFour::on_cell_11_clicked()
{
    handle_cell(1 , 1);
}


void FourXFour::on_cell_12_clicked()
{
    handle_cell(1 , 2);
}


void FourXFour::on_cell_13_clicked()
{
    handle_cell(1 , 3);
}


void FourXFour::on_cell_20_clicked()
{
    handle_cell(2 , 0);
}


void FourXFour::on_cell_21_clicked()
{
    handle_cell(2 , 1);
}


void FourXFour::on_cell_22_clicked()
{
    handle_cell(2 , 2);
}


void FourXFour::on_cell_23_clicked()
{
    handle_cell(2 , 3);
}


void FourXFour::on_cell_30_clicked()
{
    handle_cell(3 , 0);
}


void FourXFour::on_cell_31_clicked()
{
    handle_cell(3 , 1);
}


void FourXFour::on_cell_32_clicked()
{
    handle_cell(3 , 2);
}


void FourXFour::on_cell_33_clicked()
{
    handle_cell(3 , 3);
}


void FourXFour::on_Clear_clicked()
{
    ui->cell_00->setText("O");
    ui->cell_00->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
    ui->cell_01->setText("X");
    ui->cell_01->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
    ui->cell_02->setText("O");
    ui->cell_02->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
    ui->cell_03->setText("X");
    ui->cell_03->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
    ui->cell_10->setText("");
    ui->cell_11->setText("");
    ui->cell_12->setText("");
    ui->cell_13->setText("");
    ui->cell_20->setText("");
    ui->cell_21->setText("");
    ui->cell_22->setText("");
    ui->cell_23->setText("");
    ui->cell_30->setText("X");
    ui->cell_30->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
    ui->cell_31->setText("O");
    ui->cell_31->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
    ui->cell_32->setText("X");
    ui->cell_32->setStyleSheet("background-color: rgb(2, 26, 26);color: blue; font-size: 28pt; font-weight: bold;");
    ui->cell_33->setText("O");
    ui->cell_33->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            B_F->update_board(i , j , 0);
        }
    }
    moves_F = 0;
    is_empty_cell = vector<int>(16 , 1);
    for (int i = 0; i < 4; ++i) {
        is_empty_cell[i] = 0;
        is_empty_cell[15 - i] = 0;
    }
    delete B_F;
    B_F = new FXF_TIC_TAC_TOE<char>;
}

void FourXFour::makeCalculatedMove()
{
    for (int i = 0; i < 4; ++i) {
        // check if i can win in the next move
        for (int j = 0; j < 4; ++j) {
            if(is_empty_cell[i * 4 + j])
                continue;
            QString cellName = "cell_" + QString::number(i) + QString::number(j);
            QPushButton *cellButton = findChild<QPushButton*>(cellName);
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k] , ny = j + dy[k];
                if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && is_empty_cell[nx * 4 + ny] && cellButton->text() == "O")
                {
                    B_F->update_board(nx , ny , 'O');
                    B_F->update_board(i , j , 0);
                    if(B_F->is_win())
                    {
                        cellButton->setText("");
                        QString n_cellName = "cell_" + QString::number(nx) + QString::number(ny);
                        QPushButton *n_cellButton = findChild<QPushButton*>(n_cellName);
                        n_cellButton->setText("O");
                        n_cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color: red; font-size: 28pt; font-weight: bold;");
                        win_F(this, ui->Player2_name->text());
                        on_Clear_clicked();
                        return;
                    }
                    B_F->update_board(nx , ny , 0);
                    B_F->update_board(i , j , 'O');
                }
            }
        }
    }

    // if no good move make random move
    makeRandomMove();
}

