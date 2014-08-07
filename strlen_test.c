#include<stdio.h>
#include<string.h>

void test_length(char* str){

    int len = strlen(str);
    printf("length is %d\n",len);
}

void main(){

    char* a = "Hello world";
    test_length(a);
}
