#include "fivexfive.h"
#include "ui_fivexfive.h"
#include "mainwindow.h"

template <typename T>
FvXFv_TIC_TAC_TOE<T>::FvXFv_TIC_TAC_TOE() {
    this->rows = 5;
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
bool FvXFv_TIC_TAC_TOE<T>::update_board(int x, int y, T mark) {
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
void FvXFv_TIC_TAC_TOE<T>::display_board() {
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

template<typename T>
int FvXFv_TIC_TAC_TOE<T>::p1_chains() {
    int chains = 0;

    // Check rows for chains of 3
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j <= this->columns - 3; ++j) { // Ensure at least 3 cells in range
            if (this->board[i][j] == 'X' &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                chains++;
            }
        }
    }

    // Check columns for chains of 3
    for (int i = 0; i < this->columns; ++i) {
        for (int j = 0; j <= this->rows - 3; ++j) { // Ensure at least 3 cells in range
            if (this->board[j][i] == 'X' &&
                this->board[j][i] == this->board[j + 1][i] &&
                this->board[j][i] == this->board[j + 2][i]) {
                chains++;
            }
        }
    }

    // Check diagonals (top-left to bottom-right) for chains of 3
    for (int i = 0; i <= this->rows - 3; ++i) {
        for (int j = 0; j <= this->columns - 3; ++j) { // Ensure diagonal range is valid
            if (this->board[i][j] == 'X' &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2]) {
                chains++;
            }
        }
    }

    // Check diagonals (bottom-left to top-right) for chains of 3
    for (int i = 2; i < this->rows; ++i) { // Start from row 2 to avoid out-of-bounds
        for (int j = 0; j <= this->columns - 3; ++j) { // Ensure diagonal range is valid
            if (this->board[i][j] == 'X' &&
                this->board[i][j] == this->board[i - 1][j + 1] &&
                this->board[i][j] == this->board[i - 2][j + 2]) {
                chains++;
            }
        }
    }

    return chains;
}


template<typename T>
int FvXFv_TIC_TAC_TOE<T>::p2_chains() {
    int chains = 0;

    // Check rows for chains of 3
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j <= this->columns - 3; ++j) { // Ensure at least 3 cells in range
            if (this->board[i][j] == 'O' &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                chains++;
            }
        }
    }

    // Check columns for chains of 3
    for (int i = 0; i < this->columns; ++i) {
        for (int j = 0; j <= this->rows - 3; ++j) { // Ensure at least 3 cells in range
            if (this->board[j][i] == 'O' &&
                this->board[j][i] == this->board[j + 1][i] &&
                this->board[j][i] == this->board[j + 2][i]) {
                chains++;
            }
        }
    }

    // Check diagonals (top-left to bottom-right) for chains of 3
    for (int i = 0; i <= this->rows - 3; ++i) {
        for (int j = 0; j <= this->columns - 3; ++j) { // Ensure diagonal range is valid
            if (this->board[i][j] == 'O' &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2]) {
                chains++;
            }
        }
    }

    // Check diagonals (bottom-left to top-right) for chains of 3
    for (int i = 2; i < this->rows; ++i) { // Start from row 2 to avoid out-of-bounds
        for (int j = 0; j <= this->columns - 3; ++j) { // Ensure diagonal range is valid
            if (this->board[i][j] == 'O' &&
                this->board[i][j] == this->board[i - 1][j + 1] &&
                this->board[i][j] == this->board[i - 2][j + 2]) {
                chains++;
            }
        }
    }

    return chains;
}


template <typename T>
bool FvXFv_TIC_TAC_TOE<T>::is_win() {
    if(p1_chains() != p2_chains())
    {
        return true;
    }
    else{
        return false;
    }
}


template <typename T>
bool FvXFv_TIC_TAC_TOE<T>::is_draw() {
    return this->n_moves == 25;
}

template <typename T>
bool FvXFv_TIC_TAC_TOE<T>::game_is_over() {
    return this->is_win() || this->is_win();
}

FiveXFive::FiveXFive(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FiveXFive)
{
    ui->setupUi(this);
    ui->Player1_name->setAlignment(Qt::AlignCenter);
    ui->p1_score->setAlignment(Qt::AlignCenter);
    ui->p2_score->setAlignment(Qt::AlignCenter);
    ui->Player2_name->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
}

FiveXFive::~FiveXFive()
{
    delete ui;
}

void FiveXFive::setNames(QString p1 , QString p2)
{
    ui->Player1_name->setText(p1);
    ui->Player2_name->setText(p2);
}

void FiveXFive::on_Back_clicked()
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

FvXFv_TIC_TAC_TOE<char>* B_Fv = new FvXFv_TIC_TAC_TOE<char>();
int moves_Fv = 0 , p1_score_Fv = 0 , p2_score_Fv = 0;
vector<int>clicked_Fv(25);


void draw_Fv(QWidget *parent) {
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

void win_Fv(QWidget *parent , QString winner)
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



void FiveXFive::handle_cell(int x , int y)
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
    if (clicked_Fv[x * 5 + y]++) {
        return; // Ignore if the cell is already clicked
    }

    QString mark;
    QString color;

    // Determine which player's turn it is
    if (moves_Fv & 1) {
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

    if (!B_Fv->update_board(x, y, mark.toUtf8()[0])) {
        return;
    }


    // Increment moves
    moves_Fv++;
    if (moves_Fv == 24) {
        if(B_Fv->is_win())
        {
            if(B_Fv->p1_chains() > B_Fv->p2_chains())
            {
                win_Fv(this , ui->Player1_name->text());
                ui->p2_score->setText(QString::number(++p1_score_Fv));
            }
            else
            {
                win_Fv(this , ui->Player2_name->text());
                ui->p2_score->setText(QString::number(++p2_score_Fv));
            }
        }
        else
        {
            on_Clear_clicked();
            draw_Fv(this);
        }

    }

    // Handle random player
    if (ui->Player2_name->text() == "Random Player") {
        makeRandomMove();
    }

    // Handle AI player
    if(ui->Player2_name->text() == "AI Player")
    {
        makeCalcualtedMove();
    }
}



void FiveXFive::on_Clear_clicked()
{
    ui->cell_00->setText("");
    ui->cell_01->setText("");
    ui->cell_02->setText("");
    ui->cell_03->setText("");
    ui->cell_04->setText("");

    ui->cell_10->setText("");
    ui->cell_11->setText("");
    ui->cell_12->setText("");
    ui->cell_13->setText("");
    ui->cell_14->setText("");

    ui->cell_20->setText("");
    ui->cell_21->setText("");
    ui->cell_22->setText("");
    ui->cell_23->setText("");
    ui->cell_24->setText("");

    ui->cell_30->setText("");
    ui->cell_31->setText("");
    ui->cell_32->setText("");
    ui->cell_33->setText("");
    ui->cell_34->setText("");

    ui->cell_40->setText("");
    ui->cell_41->setText("");
    ui->cell_42->setText("");
    ui->cell_43->setText("");
    ui->cell_44->setText("");

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            B_Fv->update_board(i , j , 0);
        }
    }
    clicked_Fv = vector<int>(25);
    moves_Fv = 0;
}

void FiveXFive::makeRandomMove()
{
    int x = rand() % 5;
    int y = rand() % 5;
    while (!B_Fv->update_board(x , y , 'O')) {
        x = rand() % 5;
        y = rand() % 5;
    }
    clicked_Fv[x * 5 + y]++;
    QString cellName = "cell_" + QString::number(x) + QString::number(y);
    QPushButton *cellButton = findChild<QPushButton*>(cellName);
    if (cellButton) {
        cellButton->setText("O");
        cellButton->setStyleSheet("background-color: rgb(2, 26, 26);color:red; font-size: 28pt; font-weight: bold;");
    }
    moves_Fv++;
    if (moves_Fv == 24) {
        if(B_Fv->is_win())
        {
            if(B_Fv->p1_chains() > B_Fv->p2_chains())
            {
                win_Fv(this , ui->Player1_name->text());
                ui->p2_score->setText(QString::number(++p1_score_Fv));
            }
            else
            {
                win_Fv(this , ui->Player2_name->text());
                ui->p2_score->setText(QString::number(++p2_score_Fv));
            }
        }
        else
        {
            on_Clear_clicked();
            draw_Fv(this);
        }

    }
}


void FiveXFive::on_cell_00_clicked()
{
    handle_cell(0, 0);
}

void FiveXFive::on_cell_01_clicked()
{
    handle_cell(0, 1);
}

void FiveXFive::on_cell_02_clicked()
{
    handle_cell(0, 2);
}

void FiveXFive::on_cell_03_clicked()
{
    handle_cell(0, 3);
}

void FiveXFive::on_cell_04_clicked()
{
    handle_cell(0, 4);
}

void FiveXFive::on_cell_10_clicked()
{
    handle_cell(1, 0);
}

void FiveXFive::on_cell_11_clicked()
{
    handle_cell(1, 1);
}

void FiveXFive::on_cell_12_clicked()
{
    handle_cell(1, 2);
}

void FiveXFive::on_cell_13_clicked()
{
    handle_cell(1, 3);
}

void FiveXFive::on_cell_14_clicked()
{
    handle_cell(1, 4);
}

void FiveXFive::on_cell_20_clicked()
{
    handle_cell(2, 0);
}

void FiveXFive::on_cell_21_clicked()
{
    handle_cell(2, 1);
}

void FiveXFive::on_cell_22_clicked()
{
    handle_cell(2, 2);
}

void FiveXFive::on_cell_23_clicked()
{
    handle_cell(2, 3);
}

void FiveXFive::on_cell_24_clicked()
{
    handle_cell(2, 4);
}

void FiveXFive::on_cell_30_clicked()
{
    handle_cell(3, 0);
}

void FiveXFive::on_cell_31_clicked()
{
    handle_cell(3, 1);
}

void FiveXFive::on_cell_32_clicked()
{
    handle_cell(3, 2);
}

void FiveXFive::on_cell_33_clicked()
{
    handle_cell(3, 3);
}

void FiveXFive::on_cell_34_clicked()
{
    handle_cell(3, 4);
}

void FiveXFive::on_cell_40_clicked()
{
    handle_cell(4, 0);
}

void FiveXFive::on_cell_41_clicked()
{
    handle_cell(4, 1);
}

void FiveXFive::on_cell_42_clicked()
{
    handle_cell(4, 2);
}

void FiveXFive::on_cell_43_clicked()
{
    handle_cell(4, 3);
}

void FiveXFive::on_cell_44_clicked()
{
    handle_cell(4, 4);
}

void FiveXFive::makeCalcualtedMove()
{
    int last_chains = B_Fv->p2_chains();

    // Check if I can make a new chain
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (clicked_Fv[i * 5 + j] == 0) { // Only consider empty cells
                B_Fv->update_board(i, j, 'O');
                if (B_Fv->p2_chains() > last_chains) {
                    moves_Fv++;
                    QString cellName = "cell_" + QString::number(i) + QString::number(j);
                    QPushButton *cellButton = findChild<QPushButton*>(cellName);
                    if (cellButton) {
                        cellButton->setText("O");
                        cellButton->setStyleSheet("background-color: rgb(2, 26, 26); color: red; font-size: 28pt; font-weight: bold;");
                    }
                    clicked_Fv[i * 5 + j]++;
                    B_Fv->update_board(i, j, 'O'); // Confirm the move
                    if (moves_Fv == 24) {
                        if (B_Fv->is_win()) {
                            if (B_Fv->p1_chains() > B_Fv->p2_chains()) {
                                win_Fv(this, ui->Player1_name->text());
                                ui->p2_score->setText(QString::number(++p1_score_Fv));
                            } else {
                                win_Fv(this, ui->Player2_name->text());
                                ui->p2_score->setText(QString::number(++p2_score_Fv));
                            }
                        } else {
                            draw_Fv(this);
                        }
                        on_Clear_clicked();
                    }
                    return;
                }
                B_Fv->update_board(i, j, 0); // Reset the test move
            }
        }
    }

    // Check if I can stop a chain to the other player
    last_chains = B_Fv->p1_chains();
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (clicked_Fv[i * 5 + j] == 0) { // Only consider empty cells
                B_Fv->update_board(i, j, 'X');
                if (B_Fv->p1_chains() > last_chains) {
                    moves_Fv++;
                    QString cellName = "cell_" + QString::number(i) + QString::number(j);
                    QPushButton *cellButton = findChild<QPushButton*>(cellName);
                    if (cellButton) {
                        cellButton->setText("O");
                        cellButton->setStyleSheet("background-color: rgb(2, 26, 26); color: red; font-size: 28pt; font-weight: bold;");
                    }
                    clicked_Fv[i * 5 + j]++;
                    B_Fv->update_board(i, j, 0); // Reset the test move
                    B_Fv->update_board(i, j, 'O'); // Confirm the move
                    if (moves_Fv == 24) {
                        if (B_Fv->is_win()) {
                            if (B_Fv->p1_chains() > B_Fv->p2_chains()) {
                                win_Fv(this, ui->Player1_name->text());
                                ui->p2_score->setText(QString::number(++p1_score_Fv));
                            } else {
                                win_Fv(this, ui->Player2_name->text());
                                ui->p2_score->setText(QString::number(++p2_score_Fv));
                            }
                        } else {
                            draw_Fv(this);
                        }
                        on_Clear_clicked();
                    }
                    return;
                }
                B_Fv->update_board(i, j, 0); // Reset the test move
            }
        }
    }

    // If no good move, make a random move
    makeRandomMove();
}



