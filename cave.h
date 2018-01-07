#ifndef CAVE_H
#define CAVE_H

#include "objectgui.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>


class Cave : public ObjectGUI
{
public:
    Cave(QString picture, const qreal scale);
    const QString picture_ = "cave.png";
};

typedef boost::shared_ptr<Cave> Cave_sharedPtr;
typedef boost::weak_ptr<Cave> Cave_weakPtr;

#endif // CAVE_H
