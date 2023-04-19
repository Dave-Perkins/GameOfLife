#ifndef CELL_H
#define CELL_H

#include <vector>
#include "constants.h"

using namespace std;
using namespace constants;

class Cell {
private:
    Cell() = delete;
    vector<int> neighbors;
protected:
    int location;
public:
    Cell(int new_loc);
    virtual void display() = 0;
    virtual bool is_alive() = 0;
    vector<int> get_neighbors();
};

Cell::Cell(int new_loc) {
    location = new_loc;
    if (location > GRID_WIDTH && location % GRID_WIDTH != 0) {                    
        neighbors.push_back(location - GRID_WIDTH - 1);       // up, left
    }
    if (location > GRID_WIDTH) {                                    
        neighbors.push_back(location - GRID_WIDTH);           // up
    }
    if (location > GRID_WIDTH && location % GRID_WIDTH != GRID_WIDTH - 1) {   
        neighbors.push_back(location - GRID_WIDTH + 1);       // up, right
    }
    if (location % GRID_WIDTH != 0) {                                    
        neighbors.push_back(location - 1);                    // left
    }
    if (location % GRID_WIDTH != GRID_WIDTH - 1) {
        neighbors.push_back(location + 1);                    // right
    }
    if (location < GRID_WIDTH * GRID_HEIGHT - GRID_WIDTH && location % GRID_WIDTH != 0) { 
        neighbors.push_back(location + GRID_WIDTH - 1);       // down, left
    }
    if (location < GRID_WIDTH * GRID_HEIGHT - GRID_WIDTH) {
        neighbors.push_back(location + GRID_WIDTH);           // down
    }
    if (location < GRID_WIDTH * GRID_HEIGHT - GRID_WIDTH && location % GRID_WIDTH != GRID_WIDTH - 1) {
        neighbors.push_back(location + GRID_WIDTH + 1);       // down, right
    }
}

vector<int> Cell::get_neighbors() {
    return neighbors;
}

#endif 