#include<stdio.h>
#include<string.h>

void main(){

    int i = 0;
    typedef int(MyArr5)[5];

    int a;

    MyArr5 arr5;

    for(i = 0; i < 5; i++){

        arr5[i] = i+1;

    }

    for(i = 0 ; i< 5; i++){
        
        printf("%d\n",arr5[i]);

    }
    
    printf("size of arr5: %d\n",sizeof(arr5));
    printf("&arr5= %ld   &arr5+1= %ld\n",&arr5,&arr5+1);
    printf("arr5= %ld    arr+1= %ld\n",arr5,arr5+1);
}
