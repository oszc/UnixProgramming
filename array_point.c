#include<stdio.h>
#include<string.h>

void main(){

    int a;
    int *p = NULL;

    int a1[5] = {1,2,3,55,6};
    typedef int(MyArr5)[5];

    MyArr5 *pArray;
    
    pArray = &a1;

    int i = 0 ;

    for(i = 0 ; i< 5; i++){
        
        printf("%d\n",*(*pArray+i));

    }

}
