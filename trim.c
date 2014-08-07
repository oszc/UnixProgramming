#include<stdio.h>
#define null NULL

int trim(char* source,char* result){
	
	
	if(source == null || result == null){

		return -1; 
	}

	int first_index =0,last_index=strlen(source)-1;
	int count = 0;

	while(isspace(*(source+first_index))&&first_index<=last_index){

		first_index++;

	}

	while(isspace(*(source+last_index)) && last_index>0){
		last_index--;

	}
	
	count = last_index - first_index + 1;
	printf("first index:%d, last index %d\n",first_index,last_index);
	memcpy(result,source+first_index,count);
	result[count]='\0';	
	return 0;
}
void main(){
	char result[100];
	char* source = "      abcd       ";
	trim(source ,result);
	printf("%s",result);
}
