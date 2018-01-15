//author: Andrzej Dzwinski, Adam Siwak

#include "timer.h"
#include "map.h"

Timer::Timer(int period)
{
    timer_ = QTimer_sharedPtr(new QTimer(this));
    connect(&(*timer_), SIGNAL(timeout()), this, SLOT(timesUp()));
    timer_->start(period); //period in ms
}

void Timer::timesUp()
{
    Map::getInstance()->timerCallBack();
}
