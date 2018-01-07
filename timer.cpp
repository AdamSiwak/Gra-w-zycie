#include "timer.h"
#include "map.h"

Timer::Timer()
{
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(myfunction()));
    timer_->start(50); //period in ms
}

void Timer::myfunction()
{
    Map::getInstance()->timerCallBack();
}
