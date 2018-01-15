#ifndef TREE_H
#define TREE_H

//author: Andrzej Dzwinski

#include "objectgui.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>


/**
 * @brief The Tree class
 */
class Tree : public ObjectGUI
{
public:
    /**
     * @brief Tree constructor
     * @param picture
     * @param scale
     */
    Tree(QString picture, const qreal scale);
    const QString picture_ = "tree.png";
};

typedef boost::shared_ptr<Tree> Tree_sharedPtr;
typedef boost::weak_ptr<Tree> Tree_weakPtr;

#endif // TREE_H
