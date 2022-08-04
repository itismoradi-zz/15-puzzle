#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "board.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //click on board buttons
    void on_btn0_0_clicked();
    void on_btn1_0_clicked();
    void on_btn2_0_clicked();
    void on_btn3_0_clicked();
    void on_btn0_1_clicked();
    void on_btn1_1_clicked();
    void on_btn2_1_clicked();
    void on_btn3_1_clicked();
    void on_btn0_2_clicked();
    void on_btn1_2_clicked();
    void on_btn2_2_clicked();
    void on_btn3_2_clicked();
    void on_btn0_3_clicked();
    void on_btn1_3_clicked();
    void on_btn2_3_clicked();
    void on_btn3_3_clicked();

private:
    Ui::MainWindow *ui;
    Board board;
    void logic(usInt, usInt);
    QPushButton * findButton(usInt, usInt);     //return ui button by position
};
#endif // MAINWINDOW_HPP
