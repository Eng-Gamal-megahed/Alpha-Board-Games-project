#ifndef FIVEXFIVE_H
#define FIVEXFIVE_H

#include <QMainWindow>
#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>

template <class T>
class FvXFv_TIC_TAC_TOE : public Board<T>
{
public:
    FvXFv_TIC_TAC_TOE();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();

    int p1_chains();

    int p2_chains();
};

namespace Ui {
class FiveXFive;
}

class FiveXFive : public QMainWindow
{
    Q_OBJECT

public:
    explicit FiveXFive(QWidget *parent = nullptr);
    ~FiveXFive();
    void setNames(QString p1 , QString p2);
    void handle_cell(int x , int y);
    void makeRandomMove();
    void makeCalcualtedMove();

private slots:
    void on_Back_clicked();

    void on_cell_00_clicked();

    void on_cell_01_clicked();

    void on_cell_02_clicked();

    void on_cell_03_clicked();

    void on_cell_04_clicked();

    void on_cell_10_clicked();

    void on_cell_11_clicked();

    void on_cell_12_clicked();

    void on_cell_13_clicked();

    void on_cell_14_clicked();

    void on_cell_20_clicked();

    void on_cell_21_clicked();

    void on_cell_22_clicked();

    void on_cell_23_clicked();

    void on_cell_24_clicked();

    void on_cell_30_clicked();

    void on_cell_31_clicked();

    void on_cell_32_clicked();

    void on_cell_33_clicked();

    void on_cell_34_clicked();

    void on_cell_40_clicked();

    void on_cell_41_clicked();

    void on_cell_42_clicked();

    void on_cell_43_clicked();

    void on_cell_44_clicked();

    void on_Clear_clicked();

private:
    Ui::FiveXFive *ui;
};

#endif // FIVEXFIVE_H
