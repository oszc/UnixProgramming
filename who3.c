#include<stdio.h>
#include"utmplib.h"
#include<utmp.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<fcntl.h>

void showInfo(struct utmp*);
void showtime(const time_t );
int main()
{
    struct utmp* cur_utmp;
    int fd = utmp_open(UTMP_FILE);
    if(fd == -1){
        perror("can not open file:");
        exit(1);    
    }

    while((cur_utmp=load_next())!=NULL){
        if(cur_utmp->ut_type == 7)
            showInfo(cur_utmp);       
    
    }
    utmp_close();
    return 1;
}

void showInfo(struct utmp* utbufp){

    printf("%-8.8s",utbufp->ut_name);
    printf(" ");
    printf("%-8.8s ",utbufp->ut_line);
    showtime(utbufp->ut_time);
    printf("\n");

}
void showtime(const time_t time){
    
    printf("%s   ",ctime(&time));
    struct tm timestamp;
    gmtime_r(&time,&timestamp);
    printf("%d-%d-%d %d:%d",timestamp.tm_year+1900,timestamp.tm_mon,timestamp.tm_mday,timestamp.tm_hour,timestamp.tm_sec);


}

