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

	if(fd==-1){
		perror("can open path:%s",UTMP_FILE);
	}
	while(read(fd,&current_record,reclen)==reclen){

    if(current_record.ut_type==USER_PROCESS)
	showInfo(&current_record);
	
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
