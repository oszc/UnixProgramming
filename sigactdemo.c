#include <stdio.h>
#include <signal.h>
#define INPUTLEN 100

void main(){

    struct sigaction newhandler;
    sigset_t blocked;
    void inthandler();
    char x[INPUTLEN];




}