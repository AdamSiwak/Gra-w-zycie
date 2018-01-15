//author: Andrzej Dzwinski

#include "cave.h"

Cave::Cave(QString picture, const qreal scale):ObjectGUI(picture, scale)
{
    setTransformOriginPoint(-400,-400);
}
