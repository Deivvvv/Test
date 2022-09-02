#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w ;
    //QMainWindow caller;
  //  Ui::MainWindow caller;
  //  caller.setupUi(&w);
  //  w.line1 = caller.lineEdit_3;
  //  w.line2 = caller.lineEdit_3;
  //  w.line3 = caller.lineEdit_3;

    w.show();
    return a.exec();
}
