#include "cave.h"

Cave::Cave(QString picture, const qreal scale):ObjectGUI(picture, scale)
{
    setTransformOriginPoint(-200,-200);
}
