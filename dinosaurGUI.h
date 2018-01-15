#ifndef DINOSAURGUI_H
#define DINOSAURGUI_H

//author: Andrzej Dzwinski, Adam Siwak

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

/**
 * @brief The DinosaurGUI class
 */
class DinosaurGUI : public ObjectGUI
{
public:
    /**
     * @brief DinosaurGUI constructor
     * @param pictureName
     * @param skale
     * @param parent
     */
    DinosaurGUI(QString pictureName, const qreal skale, Dinosaur* parent);

    /**
     * @brief ~DinosaurGUI destructor
     */
    virtual ~DinosaurGUI() {}

    /**
     * @brief accept visitor
     * @param v
     */
    virtual void accept(Visitor& v){Q_UNUSED(v);}

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    ///functions for move GUI one step in different directions
    void stepRight();
    void stepLeft();
    void stepUp();
    void stepDown();

    /**
     * @brief beginDrinking turn the GUI 45 degrees when dinosaur dringking
     */
    void beginDrinking();

    /**
     * @brief endDrinking rotate dinosaur GUI to normal positiona after end of drinking
     */
    void endDrinking();

    Cloud_sharedPtr cloud_;
private:
    Sound_sharedPtr dinoSound;

    Dinosaur* parent_;

    static const int STEP_SIZE_ = 1;
};

typedef boost::shared_ptr<DinosaurGUI> DinosaurGUI_sharedPtr;
typedef boost::weak_ptr<DinosaurGUI> DinosaurGUI_weakPtr;

#endif // DINOSAURGUI_H
