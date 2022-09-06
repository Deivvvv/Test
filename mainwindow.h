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

    int cn =0, v=0;

    QLineEdit* line1 = nullptr;
    QLineEdit* line2 = nullptr;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void readCN(){
        line2->setText("CN " +QString::number(cn));
       // line2->setText("CN "+cn);
    };
    void readV(){
       // std::string str ="Volume "+QString::number(v) +"0%";
       // line1->setText("Volume ");
        line1->setText( "Volume "+QString::number(v) +"0%");
    };
    void selectCN(){
       QPushButton *button = (QPushButton *)sender();
       cn = button->text().toInt();
       readCN();
    };
    void CNPlus(){
       if(cn >=30)
           cn=0;
       else
           cn++;
       readCN();
    };
    void CNMinus(){
       if(cn <=0)
           cn=30;
       else
           cn--;
       readCN();
    };
    void VolumePlus(){
       if(v <=9)
           v++;
       readV();
    };
    void VolumeMinus(){
       if(v>0)
           v--;
       readV();
    };


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
