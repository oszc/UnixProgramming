//
//  main.c
//  ls1
//
//  Created by JustinZhang on 7/13/14.
//  Copyright (c) 2014 Justin. All rights reserved.
//

#include <stdio.h>
#include <dirent.h>

void do_ls(char* dir);

int main(int argc, const char * argv[])
{

    if(argc==1){
        do_ls(".");
    }else{
        while (--argc){
            do_ls(*++argv);
        }
    }

    return 0;
}

void do_ls(char* path){

    struct dirent* dirInfo;

    DIR* dir = opendir(path);

    int divider = 0;

    while ((dirInfo= readdir(dir))!= NULL){


        printf("%-8.8s\t",dirInfo->d_name);

        if(divider++%4==0){
            printf("\n");
        }
    }

    printf("\n");

}
