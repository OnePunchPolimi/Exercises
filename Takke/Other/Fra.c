#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define P 20
char* strmul(char* ,int);
int main(){
	char* c;
	int n;
	printf("parola: ");
	scanf("%s",c);
	printf("numero: ");
	scanf("%d",&n);
	c=strmul(c,n);
	printf("string: %s\n",c);
	if(c!=NULL)free(c);
	return 0;	
}

char* strmul(char* c, int n){
	int i;
	char* a=(char*)malloc(n*strlen(c)*sizeof(char)+1);
	if(a==NULL){
		printf("fail\n");
	}
	else{
		strcpy(a,c);
		for(i=n-1;i>0;i--){
			strcat(a,c);
		}
	}
	return a;
}
	
