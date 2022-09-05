#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    line1 = ui->lineEdit;
    line2 = ui->lineEdit_2;
    line3 = ui->lineEdit_3;


   // connect(ui->pushButton, SIGNAL(cliked()),SLOT(add0())));



}


MainWindow::~MainWindow()
{
    delete ui;
}

