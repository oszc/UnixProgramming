#include <stdio.h>
#include <signal.h>

void main() {

    void wakeup(int signal);
    printf("about to sleep 4 seconds\n");
    signal(SIGALRM,wakeup);
    alarm(4);
    pause();
    printf("Morning, so soon?\n");
}

void wakeup(int signal){
    printf("Alarm received from kernel\n");
}