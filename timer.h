#ifndef TIMER_H
#define TIMER_H

#include <QDebug>
#include <QTimer>
#include <QObject>

class Timer : QObject
{
    Q_OBJECT
public slots:
    void myfunction();

public:
    Timer();
    QTimer * timer_;
};

#endif // TIMER_H
