#ifndef INVERSE_H
#define INVERSE_H

#include <QMainWindow>
#include "BoardGame_Classes.h"

template <typename T>
class Inverse_Board:public Board<T> {
public:
    Inverse_Board();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

namespace Ui {
class Inverse;
}

class Inverse : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inverse(QWidget *parent = nullptr);
    ~Inverse();
    void setNames(QString p1 , QString p2);
    void handle_cell(int x , int y);
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
    Ui::Inverse *ui;
};

#endif // INVERSE_H
