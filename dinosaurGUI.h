#ifndef DINOSAURGUI_H
#define DINOSAURGUI_H

#include "sound.h"
#include "objectgui.h"

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class DinosaurGUI : public ObjectGUI
{
public:
    DinosaurGUI(QString pictureName, const qreal skale);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    Sound* dinoSound;
};

#endif // DINOSAURGUI_H
