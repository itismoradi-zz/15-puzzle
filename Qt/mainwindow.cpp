#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <iostream>
#include <exception>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn0_0_clicked()
{
    logic(0, 0);
}


void MainWindow::on_btn1_0_clicked()
{
    logic(1, 0);
}


void MainWindow::on_btn2_0_clicked()
{
    logic(2, 0);
}


void MainWindow::on_btn3_0_clicked()
{
    logic(3, 0);
}


void MainWindow::on_btn0_1_clicked()
{
    logic(0, 1);
}


void MainWindow::on_btn1_1_clicked()
{
    logic(1, 1);
}


void MainWindow::on_btn2_1_clicked()
{
    logic(2, 1);
}


void MainWindow::on_btn3_1_clicked()
{
    logic(3, 1);
}


void MainWindow::on_btn0_2_clicked()
{
    logic(0, 2);
}


void MainWindow::on_btn1_2_clicked()
{
    logic(1, 2);
}


void MainWindow::on_btn2_2_clicked()
{
    logic(2, 2);
}


void MainWindow::on_btn3_2_clicked()
{
   logic(3, 2);
}


void MainWindow::on_btn0_3_clicked()
{
    logic(0, 3);
}


void MainWindow::on_btn1_3_clicked()
{
    logic(1, 3);
}


void MainWindow::on_btn2_3_clicked()
{
    logic(2, 3);
}


void MainWindow::on_btn3_3_clicked()
{
    logic(3, 3);
}

void MainWindow::logic(usInt x, usInt y)
{
    Cell & empty = ~board;
    Cell & target = board(x, y);

    if(empty.x == target.x || empty.y == target.y)
    {
        if(empty.y == target.y - 1 || empty.y == target.y + 1 ||
           empty.x == target.x - 1 || empty.x == target.x + 1)
        {
            board.swapCells(empty.x, empty.y, target.x, target.y);
            findButton(empty.x, empty.y)->setText(QString::number(empty.value));
            findButton(x, y)->setText("");
            ui->lbl_status->setText("😎👍");
            return;
        }
    }

    ui->lbl_status->setText("😒 Can't move!");
}

QPushButton *MainWindow::findButton(usInt x, usInt y)
{
    if(x == 0)
    {
        if(y == 0)  return ui->btn0_0;
        if(y == 1)  return ui->btn0_1;
        if(y == 2)  return ui->btn0_2;
        if(y == 3)  return ui->btn0_3;
    }
    else if(x == 1)
    {
        if(y == 0)  return ui->btn1_0;
        if(y == 1)  return ui->btn1_1;
        if(y == 2)  return ui->btn1_2;
        if(y == 3)  return ui->btn1_3;
    }
    else if(x == 2)
    {
        if(y == 0)  return ui->btn2_0;
        if(y == 1)  return ui->btn2_1;
        if(y == 2)  return ui->btn2_2;
        if(y == 3)  return ui->btn2_3;
    }
    else if(x == 3)
    {
        if(y == 0)  return ui->btn3_0;
        if(y == 1)  return ui->btn3_1;
        if(y == 2)  return ui->btn3_2;
        if(y == 3)  return ui->btn3_3;
    }
    else
    {
        throw invalid_argument("Invalid position is entered!");
    }
}

