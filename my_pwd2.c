#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
/***
1.if has parent
     go to parent
  print current folder name
*/

int main(int argc,char* argv[]){

    



}

int getNodeId(char *fileName){

   int fd = open(fileName,O_RDONLY);
    
    if(fd == -1){
        perror("can not open file");
        exit(EXIT_REASON_IO_INSTRUCTION);
    }

    


}
