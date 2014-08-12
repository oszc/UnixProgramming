#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int printArray(int* array,int num);
int sort(int* array,int num);


void main(){

    int arr[] = {3,2,0,-2,5,8,23,-5};

    printArray(&arr,8);
    sort(&arr,8);
    printArray(&arr,8);



}

int printArray(int * array, int num){

    int i = 0;
    if(array != NULL){

        for(i = 0 ; i < num ; i++){

            printf("%d\t",*(array+i));

        }

        printf("\n");

    }

}


int sort(int* array,int num){


    if( array != NULL){

        int i = 0, j = 0;
        int * temp =NULL;

        for(i = 0 ; i < num ; i++){

            for ( j = i+1 ; j < num; j++){

                if(array[i] > array[j]){

                    temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                }

            }

        }

    }



}

