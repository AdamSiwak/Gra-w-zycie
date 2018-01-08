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
    virtual ~DinosaurGUI() {}
    virtual void accept(Visitor& v){}

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void stepRight();
    void stepLeft();
    void stepUp();
    void stepDown();

    void beginDrinking();
    void endDrinking();

private:
    Sound* dinoSound;
    static const int STEP_SIZE_ = 1;
};

#endif // DINOSAURGUI_H
