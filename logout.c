#include<stdio.h>
#include<utmp.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#define UTSIZE (sizeof(struct utmp))
int utmp_open(char*);
int equals(char*,char*);

int main(int argc,char* argv[]){
    struct utmp user;
    if(argc!=2) {
        
        printf("usage: a.out tty");
        exit(1);
    }

  char*target_tty= argv[1];

  int fd = utmp_open(UTMP_FILE);

  if(fd == -1){
    perror("can not open file");
    exit(1);
  
  }
  
  while(read(fd,&user,UTSIZE)==UTSIZE){
  
    if(equals(&user.ut_line,target_tty)==0){
        time(&user.ut_time);
        lseek(fd,-UTSIZE,SEEK_CUR);
        user.ut_type = DEAD_PROCESS;
        write(fd,&user,UTSIZE);
        break; 
    } 
  }
 
 close(fd);
 return 0;
}

int utmp_open(char* file){

    int fd =open(file,O_RDWR);

    return fd;

}
int equals(char* a , char* b){
    
  return strncmp(a,b,sizeof(a));

}
