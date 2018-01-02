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
    std::vector<Dinosaur*> dinosaurs_;
    std::vector<ObjectGUI*> objects_;

    QGraphicsScene* scene_;

    Timer* timer_;


public:
    static Map* getInstance(){
        if(!instance_) {
            instance_ = new Map();
        }
        return instance_;
    }

    void add_new_object(ObjectGUI *object);
    void add_new_dinosaur(Dinosaur* dinosaur);

    void createPreysPopulation(int size);
    void createPredatorsPopulation(int size);
    void createCaves(int amount);
    void createLakes(int amount);
    void createTrees(int amount);

    int get_n_dinosaurs() { return dinosaurs_.size(); }
    int get_n_objects() { return objects_.size(); }

};

#endif // MAP_H
