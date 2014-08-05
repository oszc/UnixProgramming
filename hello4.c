#include <curses.h>

void main(){

    initscr();
    clear();
    int i ;

    for ( i = 0 ; i< LINES; i++){

        move(i, i);
        if(i%2 == 1){
            standout();
        }
        addstr("Hello World!");

        if(i%2 == 1){
            standend();
        }
        refresh();
        sleep(1);
        move(i, i);
        addstr("                 ");
    }

    endwin();
}