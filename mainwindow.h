#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QString>
#include <iostream>

#include <QPushButton>
#include <string>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    int mood =0;

    QLineEdit* line1 = nullptr;
    QLineEdit* line2 = nullptr;
    QLineEdit* line3 = nullptr;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    double returnDouble(bool first){
        //stirng str ="";
        if(first)
            return line1->text().toDouble();

        return line2->text().toDouble();
    };

    void plus(){
        mood =0;
        switchMood();
    };
    void minus(){
        mood =1;
        switchMood();
    };

    void division(){
        mood =3;
        switchMood();
    };
    void multiplication(){
        mood =2;
        switchMood();
    };
    void clear(){
        if(line2->text() !="0"){
            line2->setText("0");
            return;
        }

        line1->setText("0");
    };
    void add(){
        QPushButton *button = (QPushButton *)sender();
        if(line2->text() =="Error" || line2->text() == "0")
            line2->setText(button->text());
        else
            line2->setText(line2->text() +button->text());

    };
    void results(){
        if(line2->text() =="Error" )
            return;
        double da = returnDouble(true),db= returnDouble(false);

        switch(mood){
        case(0):
            da += db;
            break;
        case(1):
            da -= db;
            break;
        case(2):
            da *= db;
            break;
        case(3):
            if(line2->text() =="0" ){
                line2->setText("Error");
                return;
            }
            da /= db;
            break;
        }


        line1->setText(QString::fromStdString(std::to_string(da)));
       // line1->setText("0");
        line2->setText("0");
    };
    void switchMood(){
        switch(mood){
        case(0):
             line3->setText("+");
            break;
        case(1):
             line3->setText("-");
            break;
        case(2):
             line3->setText("*");
            break;
        case(3):
             line3->setText("/");
            break;
        }
    };

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
