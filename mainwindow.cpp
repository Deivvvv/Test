#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // line1 = ui->lineEdit_2;
   // line2 = ui->lineEdit_3;

    imageLabel =ui->label;

    //C:\\Users\\Admin\\Documents\\untitled1\\redButton.png
    map2 = QPixmap("C:\\Users\\Admin\\Documents\\untitled1\\redButton.png");
    map1 = QPixmap("C:\\Users\\Admin\\Documents\\untitled1\\greenButton.png");


    connect(&m_timer, SIGNAL(timeout()), this, SLOT( Close()));
   // connect(ui->pushButton, SIGNAL(cliked()),SLOT(Plays()));
    Set();

    Close();
}


MainWindow::~MainWindow()
{
    delete ui;
}

