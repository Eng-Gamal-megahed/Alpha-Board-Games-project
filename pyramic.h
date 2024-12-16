#ifndef PYRAMIC_H
#define PYRAMIC_H

#include <QMainWindow>
#include <QDialog>  // Include QDialog to use exec()

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>


template <typename T>
class P_TIC_TAC_TOE : public Board<T>
{

public:

    P_TIC_TAC_TOE();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();

};

namespace Ui {
class PYRAMIC;
}

class PYRAMIC : public QMainWindow
{
    Q_OBJECT

public:
    QString player1_name , player2_name;
    explicit PYRAMIC(QWidget *parent = nullptr);
    ~PYRAMIC();
    void setNames(QString p1 , QString p2);
    void handle_cell(int x , int y);
    void makeRandomMove();
    void makeCalclutedMove();


private slots:
    void on_Back_clicked();

    void on_Clear_clicked();

    void on_cell_02_clicked();

    void on_cell_11_clicked();

    void on_cell_12_clicked();

    void on_cell_13_clicked();

    void on_cell_20_clicked();

    void on_cell_21_clicked();

    void on_cell_22_clicked();

    void on_cell_23_clicked();

    void on_cell_24_clicked();

private:
    Ui::PYRAMIC *ui;
};

#endif // PYRAMIC_H
