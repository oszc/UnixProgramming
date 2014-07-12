#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]){

    if(argc!=3){
        perror("usage: cp sourcefile destination");
    }
    char* dest = argv[2];
    char* source = argv[1];
    char buf[1024];
    int destFd = creat(dest,O_CREAT|S_IRUSR|S_IWUSR|S_IRGRP|S_IWUSR);
    int sourceFd = open(source,O_RDONLY);
    if(destFd < 0 ){
    
        perror("creat file fail");
    
    }   
    if(sourceFd < 0){
    
        perror("open file fail"); 
    }
    int len =0;
    while((len=read(sourceFd,buf,sizeof(buf)))){
    
       if(len != write(destFd,buf,len)){
           perror("error");
       } 
    } 

    close(destFd);
    close(sourceFd);
   return 0;
}
