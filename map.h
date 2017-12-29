#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>

#include "vector"
#include "predator.h"

class Map { // singleton

private:
    Map();
    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;

    static Map* instance_;
    std::vector<Dinosaur*> dinosaurs_;
    std::vector<Object*> objects_;

    QGraphicsScene * scene_;

public:
    static Map* getInstance(){
        if(!instance_) {
            instance_ = new Map();
        }
        return instance_;
    }

    void createPopulation(int size);
    void add_new_object(Object* object);
    void add_new_dinosaur(Dinosaur* dinosaur);

    int get_n_dinosaurs() { return dinosaurs_.size(); }
    int get_n_objects() { return objects_.size(); }

};

#endif // MAP_H
