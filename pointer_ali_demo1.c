#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int swip(int **a ){
    **a = 100;
}

void main(){
    
    int a = 5;
    int *pa = &a;

    swip(&pa);
    printf("%d",a);
    

}
