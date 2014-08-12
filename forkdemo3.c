#include<stdio.h>

void main(){

    int fork_rv;

    printf("Before: my pid is %d\n",getpid());

    fork_rv = fork();

    if(fork_rv==-1){
    
        perror("fork error");
    
    }else if(fork_rv == 0){
        printf("I am the child, mypid=%d \n",getpid()); 
    }else{
        printf("I am the parent,my child is %d\n",fork_rv); 
    
    }
}

