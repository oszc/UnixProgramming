#include<utmp.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<time.h>

#define BUFF 512 
int main(int argc,char* argv[]){
    int fd = open(UTMP_FILE,O_RDONLY);
    struct utmp current_record;
    int reclen = sizeof(current_record);
    char* cur_ut_line;
    int whoami = 0; 
    /**
      if user pass three params , we check the second params equals "am" and third equals "i" 
      then print current user info in current tty 
     */
    if(fd==-1){
        perror("can open path");
    }
    if(argc==3){
        if(strcmp(argv[1],"am")==0&& strcmp(argv[2],"i")==0){
            whoami = 1; 
        } 
    }
    cur_ut_line=ttyname(STDIN_FILENO);
    printf("tty name :%s \n",cur_ut_line);
    while(read(fd,&current_record,reclen)==reclen){

        if(current_record.ut_type==USER_PROCESS)
            if(whoami){
                if(strstr(cur_ut_line,current_record.ut_line)!=NULL){

                    showInfo(&current_record);
                }
            }else{
                showInfo(&current_record); 
            }
    }

}

void showInfo(struct utmp *utbufp){

    printf("%-8.8s",utbufp->ut_name);
    printf(" ");
    printf("%-8.8s ",utbufp->ut_line);
    //	printf("%12.12s",ctime(&utbufp->ut_time)+4);
    showtime(utbufp->ut_time);
    printf("\n");
}

void showtime(const time_t time){

    struct tm timestamp;
    gmtime_r(&time,&timestamp);
    // char* result = ctime(&time); 
    //printf("%s",result);
    printf("%d-%d-%d %d:%d",timestamp.tm_year+1900,timestamp.tm_mon,timestamp.tm_mday,timestamp.tm_hour,timestamp.tm_sec);

}

