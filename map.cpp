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

    createPredatorsPopulation(3);
    createPreysPopulation(5);

    view_ = new QGraphicsView(scene_);
    view_->showMaximized();

    backgroundSound_ = new Sound(BACKGROUND);
    backgroundSound_->play();

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

void Map::addNewPredator(Predator* dinosaur) {
    scene_->addItem(dinosaur->gui_);
    predators_.push_back(dinosaur);
}

void Map::addNewPrey(Prey* dinosaur) {
    scene_->addItem(dinosaur->gui_);
    preys_.push_back(dinosaur);
}

void Map::createPredatorsPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        addNewPredator(new Predator);
    }
}

void Map::createCaves(int amount)
{
    try {
        for (int i = 0; i < amount; ++i) {
            ObjectGUI_sharedPtr p(new Cave("cave.png",0.75) );
            addNewCave(p);
        }
    } catch (const std::bad_alloc& e) {
        qDebug() << "Allocation failed: " << e.what() << '\n';
    }
}

void Map::createLakes(int amount)
{
    try {
        for (int i = 0; i < amount; ++i) {
            ObjectGUI_sharedPtr p(new Lake("lake.png",0.5) );
            addNewLake(p);
        }
    } catch (const std::bad_alloc& e) {
        qDebug() << "Allocation failed: " << e.what() << '\n';
    }
}

void Map::createTrees(int amount)
{
    try {
        for (int i = 0; i < amount; ++i) {
            ObjectGUI_sharedPtr p(new Tree("tree.png",0.025) );
            addNewTree(p);
        }
    } catch (const std::bad_alloc& e) {
        qDebug() << "Allocation failed: " << e.what() << '\n';
    }
}

void Map::deleteAllObjects()
{
//    while (!preys_.empty()) {
//        Prey* p = dynamic_cast<Prey*>(*(preys_.end()--));
//        delete p;
//        preys_.pop_back();
//    }

//    while (!predators_.empty()) {
//        Predator* p =  dynamic_cast<Predator*>(*(predators_.end()--));
//        delete p;
//        predators_.pop_back();
//    }

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

Lake_weakPtr Map::getNearestLake(Dinosaur *dino)
{
    ObjectGUI_sharedPtr object = getNearestObject(dino,getLakes());
    return boost::dynamic_pointer_cast<Lake>(object);
}

Tree_weakPtr Map::getNearestTree(Dinosaur *dino)
{
    ObjectGUI_sharedPtr object = getNearestObject(dino,getTrees());
    return boost::dynamic_pointer_cast<Tree>(object);
}

Cave_weakPtr Map::getNearestCave(Dinosaur *dino)
{
    ObjectGUI_sharedPtr object = getNearestObject(dino,getCaves());
    return boost::dynamic_pointer_cast<Cave>(object);
}

Predator *Map::getNearestPredator(Dinosaur *dino)
{
    return dynamic_cast<Predator*>(getNearestObject(dino,getPredators()));
}

Prey *Map::getNearestPrey(Dinosaur *dino)
{
    return dynamic_cast<Prey*>(getNearestObject(dino,getPreys()));
}

ObjectGUI_sharedPtr Map::getNearestObject(Dinosaur *dino, std::vector<ObjectGUI_sharedPtr> objects)
{
    ObjectGUI_sharedPtr object;
    int dinoX = dino->gui_->position_->getRealXcoordinate();
    int dinoY = dino->gui_->position_->getRealYcoordinate();

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

Dinosaur *Map::getNearestObject(Dinosaur *dino, std::vector<Dinosaur *> dinosurs)
{
    Dinosaur* dinosur;
    int dinoX = dino->gui_->position_->getRealXcoordinate();
    int dinoY = dino->gui_->position_->getRealYcoordinate();

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

void Map::createPreysPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        addNewPrey(new Prey);
    }
}

