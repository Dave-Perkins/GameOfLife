#ifndef GAME_H
#define GAME_H

#include <ncurses.h>

#include "deadcell.h"
#include "alivecell.h"
#include "constants.h"

#include <vector>

using namespace std;

class Game {
private:
    vector<Cell*> all_cells;
public:
    Game();
    void display();
    void create_next_generation();
};

Game::Game() {
    for (int key = 0; key < GRID_WIDTH * GRID_HEIGHT; key++) {
        if (rand() % 3 == 0) {
            all_cells.push_back(new AliveCell(key));
        } else {
            all_cells.push_back(new DeadCell(key));
        }
        
    }
}

void Game::display() {
    clear();
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        all_cells[i]->display();
        if (i % GRID_WIDTH == GRID_WIDTH - 1) {
            cout << endl;
        }
    }
    refresh();
}

void Game::create_next_generation() {
    vector<Cell*> next_generation;
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        int num_alive_neighbors = 0;
        for (int nbr : all_cells[i]->get_neighbors()) {
            num_alive_neighbors += all_cells[nbr]->is_alive();
        }
        if (all_cells[i]->is_alive() && (num_alive_neighbors == 2 || num_alive_neighbors == 3)) {
            next_generation.push_back(new AliveCell(i));
        } else if (!all_cells[i]->is_alive() && num_alive_neighbors == 3) {
            next_generation.push_back(new AliveCell(i));
        } else {
            next_generation.push_back(new DeadCell(i));
        }
    }
    all_cells = next_generation;
}

#endif