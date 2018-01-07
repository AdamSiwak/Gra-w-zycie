#ifndef TREE_H
#define TREE_H

#include "objectgui.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

class Tree : public ObjectGUI
{
public:
    Tree(QString picture, const qreal scale);
    const QString picture_ = "tree.png";
};

typedef boost::shared_ptr<Tree> Tree_sharedPtr;
typedef boost::weak_ptr<Tree> Tree_weakPtr;

#endif // TREE_H
