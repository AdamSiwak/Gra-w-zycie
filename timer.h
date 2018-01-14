#ifndef TIMER_H
#define TIMER_H

#include <QDebug>
#include <QTimer>
#include <QObject>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<QTimer> QTimer_sharedPtr;

class Timer : QObject
{
    Q_OBJECT
public slots:
    void myfunction();

public:
    Timer(int period);
    QTimer_sharedPtr timer_;
};

typedef boost::shared_ptr<Timer> Timer_sharedPtr;

#endif // TIMER_H
