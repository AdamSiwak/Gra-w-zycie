#ifndef TREE_H
#define TREE_H

#include "objectgui.h"

class Tree : public ObjectGUI
{
public:
    Tree(QString picture, const qreal scale);
    const QString picture_ = "tree.png";
};

#endif // TREE_H
