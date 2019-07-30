// RUN::  g++ -std="c++17" main.cpp -lncurses

#include <iostream>
#include <ncurses.h>
#include <algorithm>
#include <unistd.h>

using namespace std;

int main() {

    int ch;

    initscr();
    noecho();

    string word = "HELLO";

    for(auto ch : word) {
        if(ch == 'H' || ch == 'E')
            attron(A_UNDERLINE);
        else 
            attron(A_BOLD);
        printw("%c", ch);
        refresh();
        sleep(1);
    }   

    getch();
    endwin();

    return 0;
}

