#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>

#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QLineEdit* line1 = nullptr;
    QLineEdit* line2 = nullptr;
    QLineEdit* line3 = nullptr;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void plus(){
        int a = line1->text().split(" ")[0].toInt();
        int b = line2->text().split(" ")[0].toInt();
        line3->setText("" + (a+b));
    };
    void minus(){
        std::cout <<  "Call";
    };
    void division(){};
    void multiplication(){};


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
