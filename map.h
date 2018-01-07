#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>
#include <QTimer>
#include <QMainWindow>

#include "vector"
#include "predator.h"
#include "timer.h"
#include "prey.h"
#include "tree.h"
#include "cave.h"
#include "lake.h"


class Map
{ // singleton
private:
    Map();
    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;
    ~Map(){}

    static Map* instance_;
    std::vector<Dinosaur*> predators_;
    std::vector<Dinosaur*> preys_;
    std::vector<ObjectGUI*> caves_;
    std::vector<ObjectGUI*> lakes_;
    std::vector<ObjectGUI*> trees_;

    QGraphicsScene* scene_;
    QGraphicsView* view_;
    Sound* backgroundSound_;

    Timer* timer_;

    ObjectGUI *getNearestObject(Dinosaur *dino, std::vector<ObjectGUI *> object);
    Dinosaur *getNearestObject(Dinosaur *dino, std::vector<Dinosaur*> dinosurs);

public:
    static Map* getInstance(){
        if(!instance_) {
            instance_ = new Map();
        }
        return instance_;
    }

    void startAnimation();
    void stopAnimation();

    void addNewLake(ObjectGUI* object);
    void addNewTree(ObjectGUI* object);
    void addNewCave(ObjectGUI* object);
    void addNewPredator(Predator* dinosaur);
    void addNewPrey(Prey* dinosaur);

    void createPreysPopulation(int size);
    void createPredatorsPopulation(int size);
    void createCaves(int amount);
    void createLakes(int amount);
    void createTrees(int amount);

    void deleteAllObjects();

    int get_n_preys() { return preys_.size(); }
    int get_n_predators() { return predators_.size(); }
    int get_n_lakes() { return lakes_.size(); }
    int get_n_caves() { return caves_.size(); }
    int get_n_trees() { return trees_.size(); }

    Lake *getNearestLake(Dinosaur * dino);
    Tree *getNearestTree(Dinosaur * dino);
    Cave *getNearestCave(Dinosaur * dino);
    Predator *getNearestPredator(Dinosaur * dino);
    Prey *getNearestPrey(Dinosaur * dino);

    std::vector<ObjectGUI*> getLakes(){return lakes_;}
    std::vector<ObjectGUI*> getTrees(){return trees_;}
    std::vector<ObjectGUI*> getCaves(){return caves_;}
    std::vector<Dinosaur*> getPredators(){return predators_;}
    std::vector<Dinosaur*> getPreys(){return preys_;}

    void timerCallBack();

};

#endif // MAP_H
