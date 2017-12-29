#include <QTime>
#include <cstdlib>
#include <ctime>

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "dinosaurGUI.h"
#include "sound.h"
#include <QLabel>
#include <QDebug>
#include <QMediaPlayer>
#include "backgroundgui.h"


int main(int argc, char *argv[])
{
    srand(time(NULL));

    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    BackgroundGUI back;
    scene->setBackgroundBrush(back);

    DinosaurGUI* dino2 = new DinosaurGUI("dinosaur_green.png",0.15);
    scene->addItem(dino2);

    DinosaurGUI* dino = new DinosaurGUI("dinosaur-brown.png", 0.15);
    scene->addItem(dino);

    QGraphicsView * view = new QGraphicsView(scene);
    view->showMaximized();
    view->show();

    Sound* background = new Sound(BACKGROUND);
    background->play();

    return a.exec();
}



