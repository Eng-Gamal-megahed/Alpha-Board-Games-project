#ifndef SUS_H
#define SUS_H

#include <QMainWindow>
#include "BoardGame_Classes.h"

template <typename T>
class SUS_Board : public Board<T>
{
public:

    int p1_chains = 0 , p2_chains = 0;

    SUS_Board();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();

};

namespace Ui {
class SUS;
}

class SUS : public QMainWindow
{
    Q_OBJECT

public:
    explicit SUS(QWidget *parent = nullptr);
    ~SUS();
    void setNames(QString p1 , QString p2);
    void handle_cell(int x , int y);
    void makeRandomMove();
    void makeCalculatedMove();

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
    Ui::SUS *ui;
};

#endif // SUS_H
