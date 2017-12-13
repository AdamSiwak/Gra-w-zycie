#ifndef MAP_BLOCK_H
#define MAP_BLOCK_H

#include "object.h"
#include <vector>

class MapBlock {
public:
    MapBlock(int size) : size_(size) {

    }
    MapBlock(MapBlock* parent) {
        if (parent->left == this) {

        } else if (parent->right == this) {

        } else if (parent->up == this) {

        } else if (parent->down == this) {

        }
    }

private:
    int size_;
    std::vector<Object*> objects;
    int x;
    int y;
    MapBlock* left;
    MapBlock* right;
    MapBlock* up;
    MapBlock* down;
};

#endif // MAP_BLOCK_H
