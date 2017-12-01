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

    Dinosaur* dino = new Dinosaur("dinosaur-brown.png");
    scene->addItem(dino);
    dino->QGraphicsItem::setScale(0.15);
    dino->setFlag(QGraphicsItem::ItemIsFocusable);
    dino->setFocus();
//    item->setFlag(QGraphicsItem::ItemIsSelectable);
//    item->setFlag(QGraphicsItem::ItemIsFocusScope);
//    item->setFlag(QGraphicsItem::ItemIsMovable);
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();
    return a.exec();
}
