#ifndef MAP_H
#define MAP_H

#include "vector"
#include "predator.h"

class Map { // singleton
public:
    static Map& getInstance() {
        if(!instance_) {
            instance_ = new Map;
        }
        return *instance_;
    }

    void createPopulation(int size) {
        for (int i = 0; i < size; ++i) {
            dinosaurs_.push_back(new Predator);
        }
//        for (int i = 0; i < size; ++i) {
//            dinosaurs_.push_back(new Prey);
//        }
    }

private:
    Map() {}
    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;

    static Map* instance_;
    std::vector<Dinosaur*> dinosaurs_;
};

#endif // MAP_H
