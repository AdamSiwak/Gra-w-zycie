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

Map::Map() : chartUpdateCounter(0) {
    qDebug()<<"Hello Debug";

    scene_ = QGraphicsScene_sharedPtr(new QGraphicsScene());

    BackgroundGUI back;
    scene_->setBackgroundBrush(back);
}

void Map::startAnimation(){

    predatorsChart = new Chart();
    predatorsChart->setTitle("Predators statistics");
    predatorsChart->setAnimationOptions(QChart::AllAnimations);
    predatorsChartView = new QChartView(predatorsChart);
    predatorsChartView->setRenderHint(QPainter::Antialiasing);
    predatorsChartView->resize(500,300);

    scene_->addWidget(predatorsChartView,Qt::WindowFlags(Qt::AlignLeft));

    preysChart = new Chart();
    preysChart->setTitle("Preys statistics");
    preysChart->setAnimationOptions(QChart::AllAnimations);
    preysChartView = new QChartView(preysChart);
    preysChartView->setRenderHint(QPainter::Antialiasing);
    preysChartView->resize(500,300);

    scene_->addWidget(preysChartView,Qt::WindowFlags(Qt::AlignLeft));

    predatorsStatistics_ = new StatisticsVisitor(predatorsChart);
    preysStatistics_ = new StatisticsVisitor(preysChart);

    createLakes(20);
    createTrees(20);

    createPredatorsPopulation(30);
    createPreysPopulation(60);
    createCaves(20);

    view_ = QGraphicsView_sharedPtr(new QGraphicsView(&(*scene_)));
    view_->showMaximized();

    backgroundSound_ = Sound_sharedPtr(new Sound(BACKGROUND));
    backgroundSound_->play();

    timer_ = Timer_sharedPtr(new Timer(TimerPeriod));

    srand(time(NULL));
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
    Object_sharedPtr object = getNearestObject(dino,getLakes());
    return boost::dynamic_pointer_cast<Lake>(object);
}

Tree_sharedPtr Map::getNearestTree(Dinosaur& dino)
{
    Object_sharedPtr object = getNearestObject(dino,getTrees());
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

Prey_sharedPtr Map::getNearestNotHidenPrey(Dinosaur &dino)
{
    return boost::dynamic_pointer_cast<Prey>(getNearestObject(dino, getPreys(), false, true));
}

Object_sharedPtr Map::getNearestObject(Dinosaur& dino, std::vector<ObjectGUI_sharedPtr>& objects)

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

Dinosaur_sharedPtr Map::getNearestObject(Dinosaur& dino, std::vector<Dinosaur_sharedPtr> dinosurs, bool inReproductiveAge, bool ifIsNotHiden)
{
    Dinosaur_sharedPtr dinosur = nullptr;
    int dinoX = dino.gui_->position_->getRealXcoordinate();
    int dinoY = dino.gui_->position_->getRealYcoordinate();

    int dinosurX = 0;
    int dinosurY = 0;

    int distance = 0;
    int minDistance = __INT_MAX__;

    for (auto it = dinosurs.begin(); it != dinosurs.end(); ++it) {
        if (&dino == &(**it)) {
            continue;
        }

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
            if (ifIsNotHiden){
                if(!(*it)->Dinosaur::getIsHiden()){
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

    for(auto it = preys_.begin(); it != preys_.end(); /*nothing*/) {
        if(((*it)->hunger()) <= 0 || ((*it)->age() >= (*it)->maxAge())) {
            it = preys_.erase(it);
        }
        else ++it;
    }

    for(auto it = predators_.begin(); it != predators_.end(); /*nothing*/) {
        if(((*it)->hunger()) <= 0 || ((*it)->age() >= (*it)->maxAge())) {
            it = predators_.erase(it);
        }
        else ++it;
    }

    ++chartUpdateCounter;
    if (chartUpdateCounter >= chartUpdateValue) {
        preysStatistics_->TimeMomentBegin();
        predatorsStatistics_->TimeMomentBegin();
    }
    std::vector<Dinosaur_sharedPtr> predators_cpy = predators_;
    std::vector<Dinosaur_sharedPtr> preys_cpy = preys_;
    for (auto it = preys_cpy.begin(); it != preys_cpy.end(); ++it) {
        (*it)->makeADecision();
        try{
        (*it)->behaviour();
        } catch(...){
            qDebug() << "error";
        }
        if (chartUpdateCounter >= chartUpdateValue) {
            (*it)->accept(*preysStatistics_);
        }
    }
    for (auto it = predators_cpy.begin(); it != predators_cpy.end(); ++it) {
        (*it)->makeADecision();
        try{
        (*it)->behaviour();
        } catch(...){
            qDebug() << "error";
        }
        if (chartUpdateCounter >= chartUpdateValue) {
            (*it)->accept(*predatorsStatistics_);
        }
    }

    if (chartUpdateCounter >= chartUpdateValue) {
        preysStatistics_->TimeMomentEnd();
        predatorsStatistics_->TimeMomentEnd();
        chartUpdateCounter = 0;
    }
}
