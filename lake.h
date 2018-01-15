#ifndef LAKE_H
#define LAKE_H

//author: Andrzej Dzwinski

#include "objectgui.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

/**
 * @brief The Lake class
 */
class Lake : public ObjectGUI
{
public:
    /**
     * @brief Lake constructor
     * @param picture
     * @param scale
     */
    Lake(QString picture, const qreal scale);
    const QString picture_ = "lake.png";
};

typedef boost::shared_ptr<Lake> Lake_sharedPtr;
typedef boost::weak_ptr<Lake> Lake_weakPtr;

#endif // LAKE_H
