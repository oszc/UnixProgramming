#include<utmp.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include"utmplib.h"
#define BUFF_NUM 16
#define UT_SIZE (sizeof(struct utmp))
#define NULLUT ((struct utmp*)NULL)

static char utmpbuf[UT_SIZE*BUFF_NUM];
static int utmp_fd;
static int cur_point;
static int load_num;
/**
  open file 
 */
int utmp_open(char* filename){

    utmp_fd= open(filename, O_RDONLY);
    if(utmp_fd== -1)
        perror("can not open file");

    cur_point = load_num=0;

    return utmp_fd;
}

struct utmp* load_next(){

    if(cur_point == load_num && utmp_reload()==0){
        return NULLUT; 
    }
    return (struct utmp*)&utmpbuf[(cur_point++)*UT_SIZE];
}
/**
  load struct utmp of buff size
 */
int utmp_reload(){

    ssize_t read_total;
    read_total=  read(utmp_fd,utmpbuf,UT_SIZE*BUFF_NUM);
    load_num = read_total/UT_SIZE;
    cur_point = 0;
    return read_total;
}

void utmp_close()
{

    if(utmp_fd!=-1)
    {
        close(utmp_fd);
    }

}
