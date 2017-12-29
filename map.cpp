#include "map.h"

Map* Map::instance_ = 0;

void Map::add_new_object(Object* object){
    //object->position_->setRandomCoordinates();
    objects_.push_back(object);
}

void Map::add_new_dinosaur(Dinosaur* dinosaur) {
   // dinosaur->position_->setRandomCoordinates();
    dinosaurs_.push_back(dinosaur);
}

void Map::createPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        add_new_dinosaur(new Predator);
    }
//    for (int i = 0; i < size; ++i) {
//        add_new_dinosaur(new Prey);
//    }
}
