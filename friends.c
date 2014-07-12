#include<stdio.h>
#define LEN 30

struct friend{
    char firstName[LEN];
    char lastName[LEN];

};
int main(void){

   struct friend *guy;
   struct friend guys[2]={{"Justin","Zhang"},{"Luck","Liu"}};

   guy = &guys[0];

   printf("name:%s %s\n",guy->firstName,guy->lastName);

   guy = &guys[1];
   
   printf("name:%s %s\n",guy->firstName,guy->lastName);

    exit(0);

}
