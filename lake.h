#ifndef LAKE_H
#define LAKE_H

#include "objectgui.h"

class Lake : public ObjectGUI
{
public:
    Lake(QString picture, const qreal scale);
    const QString picture_ = "lake.png";
};

#endif // LAKE_H
