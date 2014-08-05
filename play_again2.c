//
//  main.c
//  play_again2
//
//  Created by JustinZhang on 7/24/14.
//  Copyright (c) 2014 Justin. All rights reserved.
//

#include <stdio.h>
#include <termios.h>
#define QUESTION "Do you want another transaction"

void tty_mode(int);
void set_cr_noecho_mode();
int get_response(char* question);

int main(int argc, const char * argv[])
{

    tty_mode(0);
    set_cr_noecho_mode();
    get_response(QUESTION);
    tty_mode(1);
    return 0;
}

void tty_mode(int mode){

    static struct termios original_mode;

    if(mode == 0){
        tcgetattr(0, &original_mode);
    }else if(mode == 1){
        tcsetattr(0, TCSANOW, &original_mode);
    }
}

void set_cr_noecho_mode(){
    struct  termios ttystate;
    tcgetattr(0, &ttystate);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_lflag &= ~ECHO;
    ttystate.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &ttystate);
}

int get_response(char* question){

    int input;
    printf("%s? ", question);
    while (1){
        switch (input = getchar()){
            case 'n':
            case 'N':
                return 0;
            case 'y':
            case 'Y':
                return 1;
            default:
                printf("\ncannot understand %c,",input);
                printf("Please type y or n ");
        }
    }
}
