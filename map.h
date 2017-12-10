#ifndef MAP_H
#define MAP_H

#include "vector"
#include "predator.h"

class Map {
public:
    Map() {}
    Map(int start_population) {
        for (int i = 0; i < start_population; ++i) {
            dinosaurs_.push_back(new Predator);
        }

        for (int i = 0; i < start_population; ++i) {
            dinosaurs_.push_back(new Predator);
        }
    }

private:
    std::vector<Dinosaur*> dinosaurs_;
};

#endif // MAP_H
