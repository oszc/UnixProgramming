#include <stdio.h>
#include <signal.h>
#import <string.h>

#define INPUTLEN 100

int main(int argc, char* argv[]){

    void inthandler(int);
    void quithandler(int);
    char input[INPUTLEN];
    int nchars;
    signal(SIGINT,inthandler);
    signal(SIGQUIT,quithandler);

    do{
        printf("\nType a message\n");
        nchars = read(0,input, INPUTLEN-1);
        if(nchars==-1){
            perror("read error");
        }

        input[nchars]='\0';
        printf("You typed: %s",input);

    }while (strncmp(input, "quit", 4 )!=0);
    return 0;
}

void inthandler(int signum){
    printf("Received signal %d.. waiting\n",signum);
    sleep(2);
    printf("Leaving inthandler \n");
}
void quithandler(int s ){
    printf("Received signal %d.. waiting\n",s);
    sleep(3);
    printf("Leaving quithandler \n");
}