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
#include "tree.h"
#include "cave.h"
#include "lake.h"


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

    Sound* background = new Sound(BACKGROUND);
    background->play();

    timer_ = new Timer();
}

void Map::add_new_lake(ObjectGUI* object){
    scene_->addItem(object);
    lakes_.push_back(object);
}

void Map::add_new_tree(ObjectGUI* object){
    scene_->addItem(object);
    trees_.push_back(object);
}

void Map::add_new_cave(ObjectGUI* object){
    scene_->addItem(object);
    caves_.push_back(object);
}

void Map::add_new_predator(Predator* dinosaur) {
    scene_->addItem(dinosaur->gui_);
    predators_.push_back(dinosaur);
}

void Map::add_new_prey(Prey* dinosaur) {
    scene_->addItem(dinosaur->gui_);
    preys_.push_back(dinosaur);
}

void Map::createPredatorsPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        add_new_predator(new Predator);
    }
}

void Map::createCaves(int amount)
{
    for (int i = 0; i < amount; ++i) {
        add_new_cave(new Cave("cave.png",0.75));
    }
}

void Map::createLakes(int amount)
{
    for (int i = 0; i < amount; ++i) {
        add_new_lake(new Lake("lake.png",0.5));
    }
}

void Map::createTrees(int amount)
{
    for (int i = 0; i < amount; ++i) {
        add_new_tree(new Tree("tree.png",0.025));
    }
}

Coordinates *Map::getNearestLake(Dinosaur *dino)
{

}

Coordinates *Map::getNearestTree(Dinosaur *dino)
{

}

Coordinates *Map::getNearestCave(Dinosaur *dino)
{

}

Coordinates *Map::getNearestPredator(Dinosaur *dino)
{

}

Coordinates *Map::getNearestPrey(Dinosaur *dino)
{

}

void Map::timerCallBack(){

    for (auto it = preys_.begin(); it != preys_.end(); ++it) {
        (*it)->move2position((*it)->currentDestination_->getXcoordinate(),(*it)->currentDestination_->getXcoordinate());
 //        (*it)->move_to_destination(0,0);
    }
}

void Map::createPreysPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        add_new_prey(new Prey);
    }
}

