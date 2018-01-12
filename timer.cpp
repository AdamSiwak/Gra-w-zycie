#include "timer.h"
#include "map.h"

Timer::Timer(int period)
{
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(myfunction()));
    timer_->start(period); //period in ms
}

void Timer::myfunction()
{
    Map::getInstance()->timerCallBack();
}
