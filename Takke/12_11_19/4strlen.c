#include<stdio.h>
#define L 50
int main(){
	char c[L+1];
	int i;
	printf("Stringa: ");
	scanf("%s",c);
	printf("\n");
	for(i=0;c[i]!='\0';++i);
	printf("strlen:%d\n",i);
	return 0;
}