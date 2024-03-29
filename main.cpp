// RUN::  g++ -Wall -std="c++17" main.cpp -lncurses

#include <iostream>
#include <ncurses.h>
#include <algorithm>
#include <unistd.h>

using namespace std;

WINDOW *create_newwin(int height=10, int width=10, int starty=0, int startx=0);

int main(){
    initscr();
    raw();
    noecho();
    int yMax,xMax;
    getmaxyx(stdscr,yMax,xMax);

    WINDOW *win1, *win2;
    // win1 = create_newwin(10, xMax-1, 0, 0);
    // win2 = create_newwin(10, xMax-1, 10, 0);

    win1 = create_newwin(10, 10, 0, 0);
    win2 = create_newwin(10, 10, 10, 10);

    box(win1,'*','+');
    box(win2,0,0);
    refresh();

    mvwprintw(win1, 1, 1, "HELLO");
    wrefresh(win1);

    sleep(1);

    mvwprintw(win2, 1, 1, "HELLO");
    wrefresh(win2);

    // wgetch(win1); //Pause
    // wgetch(win2); //Pause

    getch();

    endwin();
    delwin(win1);
    delwin(win2);

    return 0;
}


WINDOW* create_newwin(int height, int width, int starty, int startx) {
    return newwin(height, width, starty, startx);
}

