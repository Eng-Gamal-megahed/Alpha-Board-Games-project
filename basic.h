#ifndef BASIC_H
#define BASIC_H

#include <QMainWindow>
#include "BoardGame_Classes.h"

template <typename T>
class X_O_Board:public Board<T> {
public:
    X_O_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class X_O_Player : public Player<T> {
public:
    X_O_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class X_O_Random_Player : public RandomPlayer<T>{
public:
    X_O_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};

namespace Ui {
class Basic;
}

class Basic : public QMainWindow
{
    Q_OBJECT

public:
    explicit Basic(QWidget *parent = nullptr);
    ~Basic();
    void setNames(QString p1 , QString p2);

    void makeRandomMove();

    void makeCalclutedMove();

private slots:
    void on_Back_clicked();

    void on_cell_00_clicked();

    void on_cell_01_clicked();

    void on_cell_02_clicked();

    void on_cell_10_clicked();

    void on_cell_11_clicked();

    void on_cell_12_clicked();

    void on_cell_20_clicked();

    void on_cell_21_clicked();

    void on_cell_22_clicked();

    void on_Clear_clicked();

private:
    Ui::Basic *ui;

};

#endif // BASIC_H
