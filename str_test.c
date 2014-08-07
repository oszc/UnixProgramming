#include<string.h>
#include<stdio.h>
void main(){

	char* sentence="kjfdlsakjfabcfdsalkjfabclkfjadlfabc";
	char* sub = "abc";
	char* resultP=NULL;
	int count = 0;
	while(1){	
		resultP = strstr(sentence,sub);
		if(resultP == NULL){

			break;
		}
		sentence = resultP+strlen(sub);
		count ++;
		printf("origin: %s\n",sentence);
		printf("result:%s\n",resultP);


	}

	printf("total:%d\n",count);



}
