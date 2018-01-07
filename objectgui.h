#ifndef OBJECTGUI_H
#define OBJECTGUI_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

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

typedef boost::shared_ptr<ObjectGUI> ObjectGUI_sharedPtr;
typedef boost::weak_ptr<ObjectGUI> ObjectGUI_weakPtr;

#endif // OBJECTGUI_H
