#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QDateTime>
#include <QDebug>
#include <QTimer>


class QLabelClock: public QLabel{

public:
    QTimer *timer;
    int refreshEnable;
    QLabelClock(QWidget *parent):
        QLabel(parent)
    {
        this->setText(this->now());

        timer = new QTimer(parent);
        timer->start(1);

        connect(timer,&QTimer::timeout,this, &QLabelClock::refresh);
    }


    QString now()
    {
        return (QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd zzz"));

    }

    void refresh()
    {

        this->setText(this->now());
    }

    void refreshToggle()
    {
        if(1 == refreshEnable)
            refreshEnable = 0;
        else
            refreshEnable = 1;
    }

   };
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget win;

    win.setWindowTitle("第一组");
    win.resize(200,150);
    win.setStyleSheet("background-color:black");

    QLabel *labelTemperatureText = new QLabel(&win);
    labelTemperatureText->setText("T-");
    labelTemperatureText->setGeometry(0, 50, 50, 50);
    labelTemperatureText->setStyleSheet("background-color: black; color: rgb(255,0,255);font-family: Microsoft YaHei; font-size: 30px");


    QLabel *labelTemperatureData = new QLabel(&win);

    labelTemperatureData->setText("36.5");
    labelTemperatureData->setGeometry(50, 0, 150, 150);
    labelTemperatureData->setStyleSheet("background-color: black; color: rgb(255,0,255)");


    QLabel *labelTemperatureUnit = new QLabel(&win);
    labelTemperatureUnit->setText("℃");
    labelTemperatureUnit->setGeometry(200, 0, 50, 50);
    labelTemperatureUnit->setStyleSheet("background_color: black; color: rgb(255,0,255)");

    QLabelClock *labelClock = new QLabelClock(&win);
    labelClock->setGeometry(0,110,300,30);
    labelClock->setStyleSheet("color: white;font-size: 20px");

    win.show();
    return a.exec();
}
