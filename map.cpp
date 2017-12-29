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

Map* Map::instance_ = 0;

Map::Map(){
    qDebug()<<"siema";

    scene_ = new QGraphicsScene();

    BackgroundGUI back;
    scene_->setBackgroundBrush(back);

    DinosaurGUI* dino = new DinosaurGUI("dinosaur-brown.png", 0.15);
    scene_->addItem(dino);

    createPopulation(5);
//    Prey * pred = new Prey();
//    add_new_dinosaur(pred);

    QGraphicsView * view = new QGraphicsView(scene_);
    view->showMaximized();
    view->show();

    Sound* background = new Sound(BACKGROUND);
    background->play();
}

void Map::add_new_object(Object* object){
    //object->position_->setRandomCoordinates();
    objects_.push_back(object);
}

void Map::add_new_dinosaur(Dinosaur* dinosaur) {
    scene_->addItem(dinosaur->gui_);
    dinosaurs_.push_back(dinosaur);
}

void Map::createPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        add_new_dinosaur(new Predator);
    }
//    for (int i = 0; i < size; ++i) {
//        add_new_dinosaur(new Prey);
//    }
}

