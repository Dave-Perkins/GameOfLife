#ifndef DEADCELL_H
#define DEADCELL_H

#include "cell.h"
#include "constants.h"
#include <iostream>

using namespace constants;

class DeadCell : public Cell {
private:
    DeadCell() = delete;
    int location;
public:
    DeadCell(int loc);
    void display();
    bool is_alive();
};

DeadCell::DeadCell(int loc) : Cell(loc) {
    location = loc;
}

void DeadCell::display() {
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvaddch(offset + (int) (location / GRID_WIDTH), offset + location % GRID_WIDTH, DEAD_CELL_CHAR);
}

bool DeadCell::is_alive() {
    return false;
}

#endif 