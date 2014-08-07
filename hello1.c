//
//  main.c
//  MyCursesGame
//
//  Created by JustinZhang on 7/25/14.
//  Copyright (c) 2014 Justin. All rights reserved.
//

#include <curses.h>

int main(int argc, const char * argv[])
{

    initscr();
    clear();
    move(10, 20);
    addstr("Hello World");
    move(LINES-1, 0);
    refresh();
    getch();
    endwin();
    return 0;
}
