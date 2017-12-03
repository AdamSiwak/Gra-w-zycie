#include <cstdlib>
#include <ctime>

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "dinosaurGUI.h"
#include <QLabel>
#include <QDebug>


int main(int argc, char *argv[])
{
    srand(time(NULL));

    QApplication a(argc, argv);
    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    DinosaurGUI* dino2 = new DinosaurGUI("dinosaur_green.png",0.25);
    scene->addItem(dino2);

    DinosaurGUI* dino = new DinosaurGUI("dinosaur-brown.png", 0.15);

    scene->addItem(dino);
    QGraphicsView * view = new QGraphicsView(scene);
    view->setSizeIncrement(1000,700);
    view->show();
    return a.exec();
}
