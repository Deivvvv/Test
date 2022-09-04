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

    QLineEdit* line1 = nullptr;
    QLineEdit* line2 = nullptr;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    double returnDouble(bool first){
        //stirng str ="";
        if(first)
            return line1->text().toInt();

        return line2->text().toInt();
    };

    void plus(){
        if(line2->text() =="Error" )
            return;
        int da = returnDouble(true),db= returnDouble(false);
        da += db;
        results(da);
    };
    void minus(){
        if(line2->text() =="Error" )
            return;
        int da = returnDouble(true),db= returnDouble(false);
        da -= db;
        results(da);
    };

    void division(){
        if(line2->text() =="Error" )
            return;
        if(line2->text() =="0" ){
            line2->setText("Error");
            return;
        }

        int da = returnDouble(true),db= returnDouble(false);
        da /= db;
        results(da);


    };
    void multiplication(){
        if(line2->text() =="Error" )
            return;
        int da = returnDouble(true),db= returnDouble(false);
        da *= db;
        results(da);
    };
    void clear(){
        if(line2->text() !="0"){
            line2->setText("0");
            return;
        }
        if(line1->text() !="0")
            line1->setText("0");
    };
    void add(){
        QPushButton *button = (QPushButton *)sender();
        if(line2->text() =="Error" || line2->text() == "0")
            line2->setText(button->text());
        else
            line2->setText(line2->text() +button->text());

    };
    void results(int a){
        line1->setText(""+a);
        line2->setText( "0");
    };

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
