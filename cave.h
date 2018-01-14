#ifndef CAVE_H
#define CAVE_H

#include "objectgui.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

/**
 * @brief The Cave class
 */
class Cave : public ObjectGUI
{
public:
    /**
     * @brief Cave constructor
     * @param picture
     * @param scale
     */
    Cave(QString picture, const qreal scale);
    /**
     * @brief picture_ is name of picture with extension
     */
    const QString picture_ = "cave.png";
};

typedef boost::shared_ptr<Cave> Cave_sharedPtr;
typedef boost::weak_ptr<Cave> Cave_weakPtr;

#endif // CAVE_H
