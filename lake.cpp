//author: Andrzej Dzwinski

#include "lake.h"

Lake::Lake(QString picture, const qreal scale):ObjectGUI(picture, scale)
{
    setTransformOriginPoint(-150,-120);
}
