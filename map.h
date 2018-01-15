#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>
#include <QTimer>
#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>

#include "vector"
#include "predator.h"
#include "timer.h"
#include "prey.h"
#include "tree.h"
#include "cave.h"
#include "lake.h"
#include "statictics_visitor.h"
#include "chart.h"
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

typedef boost::shared_ptr<QGraphicsScene> QGraphicsScene_sharedPtr;
typedef boost::shared_ptr<QGraphicsView> QGraphicsView_sharedPtr;

/**
 * @brief The Map class (singleton)
 */
class Map : public QObject
{ // singleton
    //Q_OBJECT
private:

    /**
     * @brief Map constructor
     */
    Map();

    /**
     * @brief Map copy constructor is forbiden
     */
    Map(const Map&) = delete;

    /**
     * @brief operator = is forbiden
     * @return
     */
    Map& operator=(const Map&) = delete;

    ~Map(){}

    /**
     * @brief TimerPeriod - period of symulation [milliseconds]
     */
    static const int TimerPeriod = 20; // ms

    /**
     * @brief instance_ - instane of singleton
     */
    static Map* instance_;

    ///vectors of objects
    std::vector<Dinosaur_sharedPtr> predators_;
    std::vector<Dinosaur_sharedPtr> preys_;
    std::vector<ObjectGUI_sharedPtr> caves_;
    std::vector<ObjectGUI_sharedPtr> lakes_;
    std::vector<ObjectGUI_sharedPtr> trees_;

    QGraphicsScene_sharedPtr scene_;
    QGraphicsView_sharedPtr view_;
    Sound_sharedPtr backgroundSound_;

    Timer_sharedPtr timer_;

    StatisticsVisitor* predatorsStatistics_;
    StatisticsVisitor* preysStatistics_;

    Chart* predatorsChart;
    QChartView* predatorsChartView;

    Chart* preysChart;
    QChartView* preysChartView;

    int chartUpdateCounter;
    static const int chartUpdateValue = (1000)/TimerPeriod; // ms

    /**
     * @brief getNearestObject compare coordinates of dino and coordinates of objects and return the nearest object
     * @param dino - dinosaur which look for some object (like cave, tree or lake)
     * @param object - lakes, caves or trees
     * @return the nearest object to dino
     */
    Object_sharedPtr getNearestObject(Dinosaur& dino, std::vector<ObjectGUI_sharedPtr>& object);

    /**
     * @brief getNearestObject compare coordinates of dino and coordinates of dinosurs and return the nearest dinosaur
     * @param dino - dinosaur which look for other dinosaur
     * @param dinosurs - predators or preys
     * @param inReproductiveAge - when this flag is set the function return only dinosaurs in reproductive age or null_ptr
     * @param ifIsNotHiden - when this flag is set the function returns onli not hidden dinosaurs of null_ptr
     * @return the nearest dinosaur
     */
    Dinosaur_sharedPtr getNearestObject(Dinosaur& dino, std::vector<Dinosaur_sharedPtr> dinosurs, bool inReproductiveAge = false, bool ifIsNotHiden = false);

public:
    /**
     * @brief getInstance
     * @return instance of singleton
     */
    static Map* getInstance(){
        if(!instance_) {
            instance_ = new Map();
        }
        return instance_;
    }

    /**
     * @brief startAnimation initiate hole symulation. Here is set basic parametrs like number od predators or preys in populatin.
     */
    void startAnimation();

    /**
     * @brief stopAnimation resets symulation
     */
    void stopAnimation();

    ///methods witch adds some objects to map
    void addNewLake(ObjectGUI_sharedPtr object);
    void addNewTree(ObjectGUI_sharedPtr object);
    void addNewCave(ObjectGUI_sharedPtr object);
    void addNewPredator(Dinosaur_sharedPtr dinosaur);
    void addNewPrey(Dinosaur_sharedPtr dinosaur);

    /**
     * @brief create - methods witch creates object
     * @param amount - number of objects
     */
    void createPreysPopulation(int amount);
    void createPredatorsPopulation(int amount);
    void createCaves(int amount);
    void createLakes(int amount);
    void createTrees(int amount);

    /**
     * @brief deleteAllObjects removes all objects from map
     */
    void deleteAllObjects();

    /**
     * @brief get_n functions
     * @return numbers od objects in vector
     */
    int get_n_preys() { return preys_.size(); }
    int get_n_predators() { return predators_.size(); }
    int get_n_lakes() { return lakes_.size(); }
    int get_n_caves() { return caves_.size(); }
    int get_n_trees() { return trees_.size(); }

    /**
     * @brief getNearest functions
     * @param dino
     * @return object witch is nearest from dino
     */
    Lake_sharedPtr getNearestLake(Dinosaur& dino);
    Tree_sharedPtr getNearestTree(Dinosaur& dino);
    Cave_sharedPtr getNearestCave(Dinosaur& dino);
    Predator_sharedPtr getNearestPredator(Dinosaur& dino);
    Prey_sharedPtr getNearestPrey(Dinosaur& dino);

    Predator_sharedPtr getNearestReproductivePredator(Dinosaur& dino);
    Prey_sharedPtr getNearestReproductivePrey(Dinosaur& dino);

    Prey_sharedPtr getNearestNotHidenPrey(Dinosaur& dino);

    std::vector<ObjectGUI_sharedPtr>& getLakes(){return lakes_;}
    std::vector<ObjectGUI_sharedPtr>& getTrees(){return trees_;}
    std::vector<ObjectGUI_sharedPtr>& getCaves(){return caves_;}
    std::vector<Dinosaur_sharedPtr>& getPredators(){return predators_;}
    std::vector<Dinosaur_sharedPtr>& getPreys(){return preys_;}

    /**
     * @brief timerCallBack - function is calls periodically by timer_. Here is hole algorithem of simulation.
     */
    void timerCallBack();

};

#endif // MAP_H
