#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "dinosaur.h"
#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0,0,100,100);
    Dinosaur* dino = new Dinosaur("dinosaur_green.png");
    QGraphicsPixmapItem *item = dino->getDino();

    // add the item to the scene
    scene->addItem(rect);
    scene->addItem(item);

    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();
    return a.exec();
}
