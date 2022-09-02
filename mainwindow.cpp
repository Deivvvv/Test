#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    line1 = ui->lineEdit;
    line2 = ui->lineEdit_2;

    connect(ui->lineEdit, SIGNAL(cliked()),SLOT(select1()));
    connect(ui->lineEdit_2, SIGNAL(cliked()),SLOT(select2()));

   // connect(ui->pushButton, SIGNAL(cliked()),SLOT(add0())));

   // connect(ui->pushButton, SIGNAL(cliked()),SLOT(plus()));
   // connect(ui->pushButton_2, SIGNAL(cliked()),SLOT(minus()));
   // connect(ui->pushButton_3, SIGNAL(cliked()),SLOT(plus()));
   // connect(ui->pushButton_4, SIGNAL(cliked()),SLOT(plus()));

}


MainWindow::~MainWindow()
{
    delete ui;
}

