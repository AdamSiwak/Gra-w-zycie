#ifndef OBJECTGUI_H
#define OBJECTGUI_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>

#include "object.h"

class ObjectGUI : public QGraphicsPixmapItem, public Object
{
public:
    ObjectGUI(QString pictureName, const qreal skale);
    virtual ~ObjectGUI() {}
    virtual void accept(Visitor& v){}
    qreal mySkale() const;
    void setMySkale(const qreal scale);
private:
    qreal scale_;
};

#endif // OBJECTGUI_H
