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

    Dinosaur* dino2 = new Dinosaur("dinosaur_green.png",0.25);
    scene->addItem(dino2);

    Dinosaur* dino = new Dinosaur("dinosaur-brown.png", 0.15);

    scene->addItem(dino);
    QGraphicsView * view = new QGraphicsView(scene);
    view->setSizeIncrement(1000,700);
    view->show();
    return a.exec();
}
