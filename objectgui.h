#ifndef OBJECTGUI_H
#define OBJECTGUI_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>

class ObjectGUI : public QGraphicsPixmapItem
{
public:
    ObjectGUI(QString pictureName, const qreal skale);
    qreal mySkale() const;
    void setMySkale(const qreal scale);
private:
    qreal scale_;
};

#endif // OBJECTGUI_H
