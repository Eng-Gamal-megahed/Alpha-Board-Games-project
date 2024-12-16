#ifndef FOURXFOUR_H
#define FOURXFOUR_H

#include <QMainWindow>
#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <map>

template <class T>
class FXF_TIC_TAC_TOE : public Board<T>
{
public:
    FXF_TIC_TAC_TOE();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();
};

namespace Ui {
class FourXFour;
}

class FourXFour : public QMainWindow
{
    Q_OBJECT

public:
    explicit FourXFour(QWidget *parent = nullptr);
    ~FourXFour();
    void setNames(QString p1 , QString p2);
    void handle_cell(int x , int y);
    void makeRandomMove();
    void makeCalculatedMove();

private slots:
    void on_Back_clicked();

    void on_cell_00_clicked();

    void on_cell_01_clicked();

    void on_cell_02_clicked();

    void on_cell_03_clicked();

    void on_cell_10_clicked();

    void on_cell_11_clicked();

    void on_cell_12_clicked();

    void on_cell_13_clicked();

    void on_cell_20_clicked();

    void on_cell_21_clicked();

    void on_cell_22_clicked();

    void on_cell_23_clicked();

    void on_cell_30_clicked();

    void on_cell_31_clicked();

    void on_cell_32_clicked();

    void on_cell_33_clicked();

    void on_Clear_clicked();

private:
    Ui::FourXFour *ui;
};

#endif // FOURXFOUR_H
