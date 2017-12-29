#include <QTime>
#include <cstdlib>
#include <ctime>

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QLabel>
#include <QDebug>
#include <QMediaPlayer>

#include "dinosaurGUI.h"
#include "sound.h"
#include "backgroundgui.h"
#include "map.h"
#include "dinosaur.h"
#include "prey.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    BackgroundGUI back;
    scene->setBackgroundBrush(back);

    DinosaurGUI* dino2 = new DinosaurGUI("dinosaur_green.png",0.15);
    scene->addItem(dino2);

    Prey* dinoo = new Prey();
    Map::getInstance().add_new_dinosaur(dinoo);

    DinosaurGUI* dino = new DinosaurGUI("dinosaur-brown.png", 0.15);
    scene->addItem(dino);

    QGraphicsView * view = new QGraphicsView(scene);
    view->showMaximized();
    view->show();

    Sound* background = new Sound(BACKGROUND);
    background->play();

    return a.exec();
}



