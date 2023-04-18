#include <iostream>
#include <vector>
#include <ctime>

#include <unistd.h> // enables the sleep() function

#include "game.h"

using namespace std;
using namespace constants;

/* Returns true if a key is pressed, false otherwise. */
bool key_is_pressed(void) {
    nodelay(stdscr, true);  // turn off getch() blocking and echo
    noecho();               // turns off echo, so user input is not displayed to the screen
    int ch;
    ch = getch();           // check for input
    bool key_pressed;
    if(ch == ERR) {
        key_pressed = false;
    } else {
        key_pressed = true;
    }
    echo();
    nodelay(stdscr, false);
    return key_pressed;
}

int main() {
    initscr();   // initializes the terminal
    cbreak();    // disables buffering and makes typed input immediately available
    curs_set(0); // turns off the cursor
    
    // resizeterm(10, 5);

    // Set the background color:
    start_color();
    init_pair(3, COLOR_MAGENTA, COLOR_MAGENTA);
    wbkgd(stdscr, COLOR_PAIR(3));
    refresh();

    // Create and run the game:
    Game g;
    while (!key_is_pressed()) {
        g.display();
        sleep(SLEEP_DURATION);
        g.create_next_generation();
    }
    endwin();
}