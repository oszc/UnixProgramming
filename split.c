#include<stdio.h>
#include<string.h>

int split(const char* source,char sign,char**buffer);

int main(){

    char* author="zhang,li,wang,yang,he";
    char authorSplit[10][30];
    split(author,',',authorSplit);

}

int split(const char* source,char sign,char**buf){

    char *ptr = source;
    char *temp =source;
    int count = 0;
    do{

        ptr =  strchr(ptr,sign);

        if(ptr == NULL){
            break;
        }
        //how go get the string
        count = ptr-temp; 
        char guessString[count+1];
        memcpy(guessString,temp,count);
        guessString[count] = '\0'; 
        printf("%s\n",guessString);
        ptr+=(sizeof(char));
        temp = ptr;
    }while(ptr!=NULL);


    return 1;
}

