#ifndef LAKE_H
#define LAKE_H

#include "objectgui.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>


class Lake : public ObjectGUI
{
public:
    Lake(QString picture, const qreal scale);
    const QString picture_ = "lake.png";
};

typedef boost::shared_ptr<Lake> Lake_sharedPtr;
typedef boost::weak_ptr<Lake> Lake_weakPtr;

#endif // LAKE_H
