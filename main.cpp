// RUN::  g++ -std="c++17" main.cpp -lncurses

#include <iostream>
#include <ncurses.h>

using namespace std;

int main() {

    int ch;

    initscr();
    noecho();

    addch('H' | A_UNDERLINE);
    addch('E' | A_UNDERLINE);
    addch('L' | A_BOLD);
    addch('L' | A_BOLD);
    addch('O' | A_BOLD);
    getch();
    endwin();

    return 0;
}
