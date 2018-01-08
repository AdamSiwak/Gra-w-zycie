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
#include <math.h>

#include "dinosaurGUI.h"
#include "sound.h"
#include "backgroundgui.h"
#include "map.h"
#include "dinosaur.h"



Map* Map::instance_ = 0;

Map::Map(){
    qDebug()<<"Hello Debug";

    scene_ = new QGraphicsScene();

    BackgroundGUI back;
    scene_->setBackgroundBrush(back);
}

void Map::startAnimation(){
    createCaves(2);
    createLakes(2);
    createTrees(2);

    createPredatorsPopulation(5);
    createPreysPopulation(5);

    view_ = new QGraphicsView(scene_);
    view_->showMaximized();

    backgroundSound_ = new Sound(BACKGROUND);
   // backgroundSound_->play(); //TODO: uncomment

    timer_ = new Timer();
}

void Map::stopAnimation(){
    delete view_;
    delete backgroundSound_;
    delete timer_;
}

void Map::addNewLake(ObjectGUI_sharedPtr object){
    scene_->addItem(&(*object));
    lakes_.push_back(object);
}

void Map::addNewTree(ObjectGUI_sharedPtr object){
    scene_->addItem(&(*object));
    trees_.push_back(object);
}

void Map::addNewCave(ObjectGUI_sharedPtr object){
    scene_->addItem(&(*object));
    caves_.push_back(object);
}

void Map::addNewPredator(Dinosaur_sharedPtr dinosaur) {
    scene_->addItem(dinosaur->gui_);
    predators_.push_back(dinosaur);
}

void Map::addNewPrey(Dinosaur_sharedPtr dinosaur) {
    scene_->addItem(dinosaur->gui_);
    preys_.push_back(dinosaur);
}

void Map::createPredatorsPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        Dinosaur_sharedPtr p(new Predator() );
        addNewPredator(p);
    }
}

void Map::createPreysPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        Dinosaur_sharedPtr p(new Prey() );
        addNewPrey(p);
    }
}

void Map::createCaves(int amount)
{
    for (int i = 0; i < amount; ++i) {
        ObjectGUI_sharedPtr p(new Cave("cave.png",0.75) );
        addNewCave(p);
    }
}

void Map::createLakes(int amount)
{
    for (int i = 0; i < amount; ++i) {
        ObjectGUI_sharedPtr p(new Lake("lake.png",0.5) );
        addNewLake(p);
    }
}

void Map::createTrees(int amount)
{
    for (int i = 0; i < amount; ++i) {
        ObjectGUI_sharedPtr p(new Tree("tree.png",0.025) );
        addNewTree(p);
    }
}

void Map::deleteAllObjects()
{
    while (!preys_.empty()) {
        preys_.pop_back();
    }

    while (!predators_.empty()) {
        predators_.pop_back();
    }

    while (!caves_.empty()) {
        caves_.pop_back();
    }

    while (!lakes_.empty()) {
        lakes_.pop_back();
    }

    while (!trees_.empty()) {
        trees_.pop_back();
    }
}

Lake_weakPtr Map::getNearestLake(Dinosaur& dino)
{
    ObjectGUI_sharedPtr object = getNearestObject(dino,getLakes());
    return boost::dynamic_pointer_cast<Lake>(object);
}

Tree_weakPtr Map::getNearestTree(Dinosaur& dino)
{
    ObjectGUI_sharedPtr object = getNearestObject(dino,getTrees());
    return boost::dynamic_pointer_cast<Tree>(object);
}

Cave_weakPtr Map::getNearestCave(Dinosaur& dino)
{
    ObjectGUI_sharedPtr object = getNearestObject(dino,getCaves());
    return boost::dynamic_pointer_cast<Cave>(object);
}

Predator_weakPtr Map::getNearestPredator(Dinosaur& dino)
{
    Dinosaur_sharedPtr object = getNearestObject(dino,getPredators());
    return boost::dynamic_pointer_cast<Predator>(object);
}

Prey_weakPtr Map::getNearestPrey(Dinosaur& dino)
{
    Dinosaur_sharedPtr object = getNearestObject(dino,getPreys());
    return boost::dynamic_pointer_cast<Prey>(object);
}

ObjectGUI_sharedPtr Map::getNearestObject(Dinosaur& dino, std::vector<ObjectGUI_sharedPtr> objects)
{
    ObjectGUI_sharedPtr object;
    int dinoX = dino.gui_->position_->getRealXcoordinate();
    int dinoY = dino.gui_->position_->getRealYcoordinate();

    int objectX = 0;
    int objectY = 0;

    int distance = 0;
    int minDistance = __INT_MAX__;


    for (auto it = objects.begin(); it != objects.end(); ++it) {

        objectX=(*it)->position_->getRealXcoordinate();
        objectY=(*it)->position_->getRealYcoordinate();

        distance = sqrt(pow((objectX - dinoX),2)+pow((objectY - dinoY),2));

        if (distance<minDistance){
            minDistance=distance;
            object = (*it);
        }
    }

    return object;
}

Dinosaur_sharedPtr Map::getNearestObject(Dinosaur& dino, std::vector<Dinosaur_sharedPtr> dinosurs)
{
    Dinosaur_sharedPtr dinosur;
    int dinoX = dino.gui_->position_->getRealXcoordinate();
    int dinoY = dino.gui_->position_->getRealYcoordinate();

    int dinosurX = 0;
    int dinosurY = 0;

    int distance = 0;
    int minDistance = __INT_MAX__;


    for (auto it = dinosurs.begin(); it != dinosurs.end(); ++it) {

        dinosurX=(*it)->gui_->position_->getRealXcoordinate();
        dinosurY=(*it)->gui_->position_->getRealYcoordinate();

        distance = sqrt(pow((dinosurX - dinoX),2)+pow((dinosurY - dinoY),2));

        if (distance<minDistance){
            minDistance=distance;
            dinosur = (*it);
        }
    }

    return dinosur;
}

void Map::timerCallBack(){

    for (auto it = preys_.begin(); it != preys_.end(); ++it) {
//        (*it)->move2position((*it)->currentDestination_->getXcoordinate(),(*it)->currentDestination_->getXcoordinate());
        (*it)->behaviour();
    }
    for (auto it = predators_.begin(); it != predators_.end(); ++it) {
//        (*it)->move2position((*it)->currentDestination_->getXcoordinate(),(*it)->currentDestination_->getXcoordinate());
        (*it)->behaviour();
    }
}
