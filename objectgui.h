#ifndef OBJECTGUI_H
#define OBJECTGUI_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

#include "object.h"


typedef boost::shared_ptr<QPixmap> QPixmap_sharedPtr;

class ObjectGUI : public Object, public QGraphicsPixmapItem
{
public:
    ObjectGUI(QString pictureName, const qreal skale);
    virtual ~ObjectGUI() {}
    virtual void accept(Visitor& v){Q_UNUSED(v);}
    qreal mySkale() const;
    void setMySkale(const qreal scale);
private:
    qreal scale_;
    QPixmap_sharedPtr pixmap_;
};

typedef boost::shared_ptr<ObjectGUI> ObjectGUI_sharedPtr;
typedef boost::weak_ptr<ObjectGUI> ObjectGUI_weakPtr;

#endif // OBJECTGUI_H
