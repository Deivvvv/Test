#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QString>
#include <iostream>

#include <QtMultimedia/QMediaPlayer>
#include <QTimer>
#include <QPushButton>
//#include <QLabel>
#include <string>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//C:/Users/Admin/Documents/untitled1/greenButton.png
    //C:/Users/Admin/Documents/untitled1/redButton.png
    int cn =0, v=0;
    bool use=false;

    QTimer m_timer;


    QMediaPlayer *player ;
    QLabel *imageLabel = nullptr;
    QPixmap map1;
    QPixmap map2;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Plays(){
        if(!use){
            imageLabel->setPixmap(map2);
            use = true;

            player->play();
            m_timer.setSingleShot(true); // If you only want it to fire once
            m_timer.start(250);
           // QTimer::singleShot(20 ,Close());
//Close();
        }
    };

    void Close(){
        imageLabel->setPixmap(map1);
        use = false;
        player->stop();
    };

    void Set(){

        player= new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:\\Users\\Admin\\Documents\\untitled1\\zwuk.mp3"));
        player->setVolume(50);
    };

    void ReSize(){
       // imageLabel->setPixmap(QPixmap::fromImage(blurImage(sourceImage, newValue).scaled(
       //                                    imageLabel->width(),
       //                                    imageLabel->height(), Qt::KeepAspectRatio)));
    };


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
