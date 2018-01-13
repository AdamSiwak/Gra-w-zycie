#ifndef DINOSAURGUI_H
#define DINOSAURGUI_H

#include "sound.h"
#include "objectgui.h"
#include "coordinates.h"

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "cloud.h"

class Dinosaur;

typedef boost::shared_ptr<Dinosaur> Dinosaur_sharedPtr;
typedef boost::weak_ptr<Dinosaur> Dinosaur_weakPtr;

class DinosaurGUI : public ObjectGUI
{
public:
    DinosaurGUI(QString pictureName, const qreal skale, Dinosaur* parent);
    virtual ~DinosaurGUI() {}
    virtual void accept(Visitor& v){Q_UNUSED(v);}

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void stepRight();
    void stepLeft();
    void stepUp();
    void stepDown();

    void beginDrinking();
    void endDrinking();

    Cloud* cloud_;
private:
    Sound_sharedPtr dinoSound;

    Dinosaur* parent_;

    static const int STEP_SIZE_ = 1;
};

typedef boost::shared_ptr<DinosaurGUI> DinosaurGUI_sharedPtr;
typedef boost::weak_ptr<DinosaurGUI> DinosaurGUI_weakPtr;

#endif // DINOSAURGUI_H
