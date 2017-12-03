#ifndef MAP_BLOCK_H
#define MAP_BLOCK_H

#include "object.h"

class MapBlock {
public:
    MapBlock(int size, int x, int y) : size_(size) {
        objects = new Object**[size_];

        for (int i = 1; i < size_; i++)
            objects[i] = new Object*;
    }

private:
    int size_;
    Object*** objects;
    int x;
    int y;
    MapBlock* left;
    MapBlock* right;
    MapBlock* up;
    MapBlock* down;
}

#endif // MAP_BLOCK_H
