#ifndef DINOSAURGUI_H
#define DINOSAURGUI_H

#include "sound.h"
#include "objectgui.h"
#include "coordinates.h"

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

    void stepRight();
    void stepLeft();
    void stepUp();
    void stepDown();

protected:
    Coordinates* coordinates_;
private:
    Sound* dinoSound;
    static const int STEP_SIZE_ = 5;
};

#endif // DINOSAURGUI_H
