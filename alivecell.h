#ifndef ALIVECELL_H
#define ALIVECELL_H

#include "cell.h"
#include "constants.h"
#include <iostream>

using namespace constants;

class AliveCell : public Cell {
private:
    AliveCell() = delete;
    int location;
public:
    AliveCell(int loc);
    void display();
};

AliveCell::AliveCell(int loc) : Cell(true, loc) {
    location = loc;
}

void AliveCell::display() {
    start_color();
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    attron(COLOR_PAIR(2));
    mvaddch(offset + (int) (location / GRID_WIDTH), offset + location % GRID_WIDTH, ALIVE_CELL_CHAR);
}

#endif