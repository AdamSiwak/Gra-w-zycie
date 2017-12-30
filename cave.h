#ifndef CAVE_H
#define CAVE_H

#include "objectgui.h"


class Cave : public ObjectGUI
{
public:
    Cave(QString picture, const qreal scale);
    const QString picture_ = "cave.png";
};

#endif // CAVE_H
