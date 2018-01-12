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
#include "cloud.h"

#include "chart.h"
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

Map* Map::instance_ = 0;

Map::Map(){
    qDebug()<<"Hello Debug";

    scene_ = QGraphicsScene_sharedPtr(new QGraphicsScene());

    BackgroundGUI back;
    scene_->setBackgroundBrush(back);
}

void Map::startAnimation(){

    predatorsChart = new Chart;
    predatorsChart->setTitle("Dynamic spline chart");
    predatorsChart->legend()->hide();
    predatorsChart->setAnimationOptions(QChart::AllAnimations);
    predatorsChartView = new QChartView(predatorsChart);
    predatorsChartView->setRenderHint(QPainter::Antialiasing);
    predatorsWindow.setCentralWidget(predatorsChartView);
    predatorsWindow.resize(400, 300);
    predatorsWindow.show();

    preysChart = new Chart;
    preysChart->setTitle("Dynamic spline chart");
    preysChart->legend()->hide();
    preysChart->setAnimationOptions(QChart::AllAnimations);
    preysChartView = new QChartView(predatorsChart);
    preysChartView->setRenderHint(QPainter::Antialiasing);
    preysWindow.setCentralWidget(preysChartView);
    preysWindow.resize(400, 300);
    preysWindow.show();

    predatorsStatistics_ = new StatisticsVisitor(predatorsChart);
    preysStatistics_ = new StatisticsVisitor(preysChart);

    createLakes(2);
    createTrees(2);
    createCaves(2);
    createPredatorsPopulation(5);
    createPreysPopulation(5);

    view_ = QGraphicsView_sharedPtr(new QGraphicsView(&(*scene_)));
    view_->showMaximized();

    backgroundSound_ = Sound_sharedPtr(new Sound(BACKGROUND));
    // backgroundSound_->play(); //TODO: uncomment

    timer_ = Timer_sharedPtr(new Timer());
}

void Map::stopAnimation(){
    view_.reset();
    backgroundSound_.reset();
    timer_.reset();
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
    scene_->addItem(&(*dinosaur->gui_));
    scene_->addItem(&(*dinosaur->gui_->cloud_));
    predators_.push_back(dinosaur);
}

void Map::addNewPrey(Dinosaur_sharedPtr dinosaur) {
    scene_->addItem(&(*dinosaur->gui_));
    scene_->addItem(&(*dinosaur->gui_->cloud_));
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

Lake_sharedPtr Map::getNearestLake(Dinosaur& dino)
{
    Object_sharedPtr object = getNearestObject(dino,static_cast<std::vector<ObjectGUI_sharedPtr>>(getLakes()));
    return boost::dynamic_pointer_cast<Lake>(object);
}

Tree_sharedPtr Map::getNearestTree(Dinosaur& dino)
{
    Object_sharedPtr object = getNearestObject(dino,(getTrees()));
    return boost::dynamic_pointer_cast<Tree>(object);
}

Cave_sharedPtr Map::getNearestCave(Dinosaur& dino)
{
    Object_sharedPtr object = getNearestObject(dino,getCaves());
    return boost::dynamic_pointer_cast<Cave>(object);
}

Predator_sharedPtr Map::getNearestPredator(Dinosaur& dino)
{
    Object_sharedPtr object = getNearestObject(dino,getPredators());
    return boost::dynamic_pointer_cast<Predator>(object);
}

Prey_sharedPtr Map::getNearestPrey(Dinosaur& dino)
{
    Object_sharedPtr object = getNearestObject(dino,getPreys());
    return boost::dynamic_pointer_cast<Prey>(object);
}

Predator_sharedPtr Map::getNearestReproductivePredator(Dinosaur &dino)
{
    return boost::dynamic_pointer_cast<Predator>(getNearestObject(dino, getPredators(), true));
}

Prey_sharedPtr Map::getNearestReproductivePrey(Dinosaur &dino)
{
    return boost::dynamic_pointer_cast<Prey>(getNearestObject(dino, getPreys(), true));
}

Object_sharedPtr Map::getNearestObject(Dinosaur& dino, std::vector<ObjectGUI_sharedPtr> objects)
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

Dinosaur_sharedPtr Map::getNearestObject(Dinosaur& dino, std::vector<Dinosaur_sharedPtr> dinosurs, bool inReproductiveAge)
{
    Dinosaur_sharedPtr dinosur = nullptr;
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
            if (inReproductiveAge == true){
                if((*it)->age()>Dinosaur::getReproductiveAge()){
                    dinosur = (*it);
                }
            }
            else{
                dinosur = (*it);
            }
        }
    }
    return dinosur;
}

void Map::timerCallBack(){
    preysStatistics_->TimeMomentBegin();
    predatorsStatistics_->TimeMomentBegin();

    for (auto it = preys_.begin(); it != preys_.end(); ++it) {
//        (*it)->move2position((*it)->currentDestination_->getXcoordinate(),(*it)->currentDestination_->getXcoordinate());
        (*it)->makeADecision();
        (*it)->behaviour();
        (*it)->accept(*preysStatistics_);
    }
    for (auto it = predators_.begin(); it != predators_.end(); ++it) {
//        (*it)->move2position((*it)->currentDestination_->getXcoordinate(),(*it)->currentDestination_->getXcoordinate());
        (*it)->makeADecision();
        (*it)->behaviour();
        (*it)->accept(*predatorsStatistics_);
    }

    preysStatistics_->TimeMomentEnd();
    predatorsStatistics_->TimeMomentEnd();

    qDebug() << "preys: \n" << preysStatistics_->toString();
    qDebug() << "predators: \n" << predatorsStatistics_->toString();
}
