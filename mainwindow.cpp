#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegExp>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString curentText){
        QRegularExpression exp("^(\\+)([0-9])$");
        if(exp.match(curentText).hasMatch())
            setOkLable();
        else
            setNonOkLable();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLable()
{
    ui->label->setText("Ok");
    ui->label->setStyleSheet("QLabel {color : green;}");
}

void MainWindow::setNonOkLable()
{
    ui->label->setText("Non Ok");
    ui->label->setStyleSheet("QLabel {color : red;}");
}

