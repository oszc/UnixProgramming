#include<utmp.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF 512 
int main(int argc,char* argv[]){
	int fd = open(UTMP_FILE,O_RDONLY);
	struct utmp current_record;
	int reclen = sizeof(current_record);

	if(fd==-1){
		perror("can open path:%s",UTMP_FILE);
	}
	while(read(fd,&current_record,reclen)==reclen){

	//		printf("%s\n",current_record.ut_user);
	showInfo(&current_record);
	
	}

}

void showInfo(struct utmp *utbufp){

	printf("%-8.8s",utbufp->ut_name);
	printf(" ");
	printf("%-8.8s ",utbufp->ut_line);
	printf("%10ld ",utbufp->ut_time);
	printf("\n");

}
