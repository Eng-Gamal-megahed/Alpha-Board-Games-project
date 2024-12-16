#ifndef WORD_H
#define WORD_H

#include <QMainWindow>
#include "BoardGame_Classes.h"
#include <map>

template <typename T>
class Word_TIC_TAC_TOE_Board : public Board<T> {
private:
    map<string , bool> is_valid;
public:
    Word_TIC_TAC_TOE_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

namespace Ui {
class Word;
}

class Word : public QMainWindow
{
    Q_OBJECT

public:
    explicit Word(QWidget *parent = nullptr);
    ~Word();
    void setNames(QString p1 , QString p2);
    void handle_cell(int x , int y , char l);
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
    Ui::Word *ui;
};

#endif // WORD_H
