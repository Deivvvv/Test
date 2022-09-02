#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <iostream>

#include <QString>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    bool first;
    QString a ="",b="";
    QLineEdit* line1 = nullptr;
    QLineEdit* line2 = nullptr;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    double returnDouble(bool first){
        QStirng str ="";
        if(first)
            str = a;
        else
            str = b;
        //(first)? a:b;
        return str.toDouble();
    };

    void plus(){
        double da = returnDouble(true),db= returnDouble(false);
        da += db;
        a = "" +da;
      //  a +=b;
        b="";
        result();
    };
    void minus(){
       // a -=b;
        b="";
        result();
    };
    void division(){
        if(b == ""){
            line2->setText("Error");
        }else{
         //   a/=b;
          //  b=0;
          //  result();
        }

    };
    void multiplication(){
       // a*=b;
        b="";
        result();
    };
    void clear(){
        (first) ? a="":b="";
        result();
    };
    void result(){
        if(a == "")
            line1->setText("0");
        else
            line1->setText(a);
        if(b == "")
            line2->setText("0");
        else
            line2->setText(b);
    };
    void add(int d){
        //QString str = ((QPushButton*)sender())->text();
       // int d = str.split(" ")[0].toInt();
        if(first)
            a+=""+d;
        else
            b+=""+d;

        result();
    };
    void select1(){
        first =true;
    };
    void select2(){
        first =false;
    };
    void add0(){add(0);};
    void add1(){add(1);};
    void add2(){add(2);};
    void add3(){add(3);};
    void add4(){add(4);};
    void add5(){add(5);};
    void add6(){add(6);};
    void add7(){add(7);};
    void add8(){add(8);};
    void add9(){add(9);};

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
