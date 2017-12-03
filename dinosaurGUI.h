#ifndef DINOSAURGUI_H
#define DINOSAURGUI_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>


class DinosaurGUI : public QGraphicsPixmapItem
{
public:
    DinosaurGUI();
    DinosaurGUI(QString dinoName, const qreal skale);
    void keyPressEvent(QKeyEvent *event);
    qreal mySkale() const;
    void setMySkale(const qreal scale);

private:
    qreal scale_;
};

#endif // DINOSAURGUI_H
