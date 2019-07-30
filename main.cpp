// RUN::  g++ -Wall -std="c++17" main.cpp -lncurses

#include <iostream>
#include <ncurses.h>
#include <algorithm>
#include <unistd.h>

using namespace std;

WINDOW *create_newwin(int height, int width, int starty, int startx);

int main(){
    initscr();
    raw();
    noecho();
    int yMax,xMax;
    getmaxyx(stdscr,yMax,xMax);

    WINDOW *win1, *win2;
    win1 = create_newwin(10, xMax-1, 0, 0);
    win2 = create_newwin(10, xMax-1, 10, 0);

    box(win1,0,0);
    box(win2,0,0);

    mvwprintw(win1, 1, 1, "HELLO");
    wrefresh(win1);

    sleep(1);

    mvwprintw(win2, 1, 1, "HELLO");
    wrefresh(win2);

    // refresh();
    wgetch(win1); //Pause
    wgetch(win2); //Pause

    delwin(win1);
    delwin(win2);
    endwin();

    return 0;
}


WINDOW* create_newwin(int height, int width, int starty, int startx) {
    return newwin(height, width, starty, startx);
}

