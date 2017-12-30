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
    qDebug()<<"Hello Debug";

    scene_ = new QGraphicsScene();

    BackgroundGUI back;
    scene_->setBackgroundBrush(back);

    createCaves(2);
    createLakes(2);
    createTrees(2);

    createPredatorsPopulation(5);
    createPreysPopulation(5);

    QGraphicsView * view = new QGraphicsView(scene_);
    view->showMaximized();
    view->show();

    Sound* background = new Sound(BACKGROUND);
    background->play();
}

void Map::add_new_object(ObjectGUI* object){
    scene_->addItem(object);
    objects_.push_back(object);
}

void Map::add_new_dinosaur(Dinosaur* dinosaur) {
    scene_->addItem(dinosaur->gui_);
    dinosaurs_.push_back(dinosaur);
}

void Map::createPredatorsPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        add_new_dinosaur(new Predator);
    }
}

void Map::createCaves(int amount)
{
    for (int i = 0; i < amount; ++i) {
        add_new_object(new ObjectGUI("cave.png",0.75));
    }
}

void Map::createLakes(int amount)
{
    for (int i = 0; i < amount; ++i) {
        add_new_object(new ObjectGUI("lake.png",0.5));
    }
}

void Map::createTrees(int amount)
{
    for (int i = 0; i < amount; ++i) {
        add_new_object(new ObjectGUI("tree.png",0.035));
    }
}

void Map::createPreysPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        add_new_dinosaur(new Prey);
    }
}

