#ifndef TIMER_H
#define TIMER_H

#include <QDebug>
#include <QTimer>
#include <QObject>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

/**
 * @brief The Timer class
 */
class Timer : QObject
{
    Q_OBJECT
public slots:

    /**
     * @brief timesUp slot wich is called when is timeout signal
     */
    void timesUp();

public:

    /**
     * @brief Timer constructor
     * @param period
     */
    Timer(int period);

    QTimer * timer_;
};

typedef boost::shared_ptr<Timer> Timer_sharedPtr;

#endif // TIMER_H
