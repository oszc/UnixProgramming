#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
/***
1.if has parent
     go to parent
  print current folder name
*/
void printNodeName();
ino_t getNodeId(char *file_path);
char* getNodeName(ino_t nodetofind);

int main(int argc,char* argv[]){

    
    printNodeName(".");
    printf("\n");
    return 0;


}

void printNodeName(char* path){

    if(getNodeId("..")!=getNodeId(path)){
    
        chdir(".."); 
        char* name = getNodeName(getNodeId(path));
        printNodeName(path);
        printf("/%s",name);
    }    

}

ino_t getNodeId(char *file_path){

    struct stat fileStat;

    int ret= stat(file_path,&fileStat);
   
    if(ret == -1){
        perror("can not read stat");
        exit(1);
    }

    printf("node id:%d\n",fileStat.st_ino);
    return fileStat.st_ino;
    
}

char* getNodeName(ino_t nodetofind){

    
    DIR *dir = opendir(".");
    if(dir == NULL){
        
        perror("can not open dir");
        exit(1);
    
    }

    struct dirent *dirent;

    while ((dirent = readdir(dir))!=NULL){
        
        if(dirent->d_ino == nodetofind){
            return dirent->d_name; 
        }
    
    }

    return NULL;


}
