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
#include <QSlider>
#include <QGraphicsBlurEffect>

#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    QSlider *slider;
    QLabel *imageLabel = nullptr;
    QPixmap map1;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QImage applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent = 0)
    {
        if(src.isNull()) return QImage();   //No need to do anything else!
        if(!effect) return src;             //No need to do anything else!
        QGraphicsScene scene;
        QGraphicsPixmapItem item;
        item.setPixmap(QPixmap::fromImage(src));
        item.setGraphicsEffect(effect);
        scene.addItem(&item);
        QImage res(src.size()+QSize(extent*2, extent*2), QImage::Format_ARGB32);
        res.fill(Qt::transparent);
        QPainter ptr(&res);
        scene.render(&ptr, QRectF(), QRectF( -extent, -extent, src.width()+extent*2, src.height()+extent*2 ) );
        return res;
    }

public slots:

    void Set(){
        // map1.setBlurRadius();
       //  map1.setBlurHints();
        QString path = "C:\\Users\\Admin\\Documents\\untitled1\\greenButton.png";
        QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
        blur->setBlurRadius(slider->value());
        QImage source(path);
        QImage result = applyEffectToImage( source, blur);
        imageLabel->setPixmap(QPixmap::fromImage(result));

//
   //     QImage blurImage(QImage source, int blurRadius);


     //  imageLabel->setPixmap(QPixmap::fromImage(blurImage(map1, slider.value()).scaled(
     //                                      imageLabel->width(),
      //                                      imageLabel->height(), Qt::KeepAspectRatio)));
    };



private:



    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
