#ifndef TIMER_H
#define TIMER_H

#include <QDebug>
#include <QTimer>
#include <QObject>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

class Timer : QObject
{
    Q_OBJECT
public slots:
    void myfunction();

public:
    Timer();
    QTimer * timer_;
};

typedef boost::shared_ptr<Timer> Timer_sharedPtr;

#endif // TIMER_H
