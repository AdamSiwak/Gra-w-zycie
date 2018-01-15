//author: Andrzej Dzwinski

#include "tree.h"

Tree::Tree(QString picture, const qreal scale):ObjectGUI(picture,scale)
{
    setTransformOriginPoint(0,-100);
}
