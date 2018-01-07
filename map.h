#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>
#include <QTimer>
#include <QMainWindow>

#include "vector"
#include "predator.h"
#include "timer.h"


class Map : QMainWindow
{ // singleton
    Q_OBJECT

public slots:
    void timerCallBack();

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

    Timer* timer_;


public:
    static Map* getInstance(){
        if(!instance_) {
            instance_ = new Map();
        }
        return instance_;
    }

    void add_new_lake(ObjectGUI* object);
    void add_new_tree(ObjectGUI* object);
    void add_new_cave(ObjectGUI* object);
    void add_new_predator(Predator* dinosaur);
    void add_new_prey(Prey* dinosaur);

    void createPreysPopulation(int size);
    void createPredatorsPopulation(int size);
    void createCaves(int amount);
    void createLakes(int amount);
    void createTrees(int amount);

    int get_n_preys() { return preys_.size(); }
    int get_n_predators() { return predators_.size(); }
    int get_n_lakes() { return lakes_.size(); }
    int get_n_caves() { return lakes_.size(); }
    int get_n_trees() { return lakes_.size(); }

    Coordinates *getNearestLake(Dinosaur * dino);
    Coordinates *getNearestTree(Dinosaur * dino);
    Coordinates *getNearestCave(Dinosaur * dino);
    Coordinates *getNearestPredator(Dinosaur * dino);
    Coordinates *getNearestPrey(Dinosaur * dino);

    std::vector<ObjectGUI*> getLakes(){return lakes_;}
    std::vector<ObjectGUI*> getTrees(){return trees_;}
    std::vector<ObjectGUI*> getCaves(){return caves_;}
    std::vector<Dinosaur*> getPredators(){return predators_;}
    std::vector<Dinosaur*> getPreys(){return preys_;}

};

#endif // MAP_H
