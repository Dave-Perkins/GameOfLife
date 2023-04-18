#ifndef CELL_H
#define CELL_H

#include <vector>
#include "constants.h"

using namespace std;
using namespace constants;

class Cell {
private:
protected:
    Cell() = delete;
    bool alive;
    int key;
    vector<int> neighbors;
public:
    Cell(bool is_alive, int new_key);
    virtual void display() = 0;
    bool is_alive();
    vector<int> get_neighbors();
};

Cell::Cell(bool currently_alive, int new_key) {
    alive = currently_alive;
    key = new_key;
    if (new_key > GRID_WIDTH && new_key % GRID_WIDTH != 0) {                    
        neighbors.push_back(new_key - GRID_WIDTH - 1);       // up, left
    }
    if (new_key > GRID_WIDTH) {                                    
        neighbors.push_back(new_key - GRID_WIDTH);           // up
    }
    if (new_key > GRID_WIDTH && new_key % GRID_WIDTH != GRID_WIDTH - 1) {   
        neighbors.push_back(new_key - GRID_WIDTH + 1);       // up, right
    }
    if (new_key % GRID_WIDTH != 0) {                                    
        neighbors.push_back(new_key - 1);                    // left
    }
    if (new_key % GRID_WIDTH != GRID_WIDTH - 1) {
        neighbors.push_back(new_key + 1);                    // right
    }
    if (new_key < GRID_WIDTH * GRID_HEIGHT - GRID_WIDTH && new_key % GRID_WIDTH != 0) { 
        neighbors.push_back(new_key + GRID_WIDTH - 1);       // down, left
    }
    if (new_key < GRID_WIDTH * GRID_HEIGHT - GRID_WIDTH) {
        neighbors.push_back(new_key + GRID_WIDTH);           // down
    }
    if (new_key < GRID_WIDTH * GRID_HEIGHT - GRID_WIDTH && new_key % GRID_WIDTH != GRID_WIDTH - 1) {
        neighbors.push_back(new_key + GRID_WIDTH + 1);       // down, right
    }
}

bool Cell::is_alive() {
    return alive;
}

vector<int> Cell::get_neighbors() {
    return neighbors;
}

#endif 