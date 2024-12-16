#ifndef NUMARIC_H
#define NUMARIC_H

#include <QMainWindow>

#include "BoardGame_Classes.h"

template <typename T>
class NUM_TIC_TAC_TOE_Board : public Board<T> {
public:
    NUM_TIC_TAC_TOE_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};


namespace Ui {
class Numaric;
}

class Numaric : public QMainWindow
{
    Q_OBJECT

public:
    explicit Numaric(QWidget *parent = nullptr);
    ~Numaric();
    void setNames(QString p1 , QString p2);
    void handle_cell(int x , int y , int num);
    void makeRandomMove();
    void makeCalculatedMove();


private slots:
    void on_Back_clicked();

    void on_Clear_clicked();

    void on_cell_00_clicked();

    void on_cell_01_clicked();

    void on_cell_02_clicked();

    void on_cell_10_clicked();

    void on_cell_11_clicked();

    void on_cell_12_clicked();

    void on_cell_20_clicked();

    void on_cell_21_clicked();

    void on_cell_22_clicked();

private:
    Ui::Numaric *ui;
};

#endif // NUMARIC_H
