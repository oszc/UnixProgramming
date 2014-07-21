#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
/***
1.if has parent
     go to parent
  print current folder name
*/
#define BUF_LEN 256
ino_t getNodeIdFrom(char*);
void inode_to_name(ino_t inode,char* buf,int buf_len);

int main(int argc,char* argv[]){

    
    printPath(".");
    printf("\n");
    exit(1);


}

void printPath(char* filePath){

    ino_t nodeId = getNodeIdFrom(filePath);
    char buf[BUF_LEN];
    if(nodeId!=getNodeIdFrom("..")){
    
        if(chdir("..")==-1){
            perror("chdir fail");
            exit(1);
        } 

        inode_to_name(nodeId,buf,BUF_LEN);
        printPath(".");
        printf("/%s",buf);
         
    }
}
ino_t getNodeIdFrom(char *filePath){

  struct stat stat_buf;
  if(stat(filePath,&stat_buf)==-1){
    perror("can not stat");
    exit(1);
  }

  return stat_buf.st_ino;

}

void inode_to_name(ino_t inode,char* buf,int buf_len){

    DIR *dir = opendir(".");
    if(dir == NULL){
    
        perror("can not open dir");
        exit(1);
    
    }
    
    struct dirent* direntP;

    while((direntP=readdir(dir))!=NULL){
    
        if(direntP->d_ino==inode){
            strncpy(buf,direntP->d_name,buf_len);
            closedir(dir);
            return;
        } 
    }
}
