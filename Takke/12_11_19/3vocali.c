
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define L 50

int main(){
	char c[L+1];
	printf("Stringa: ");
	scanf("%s",c);
	printf("\n");
	int count=0;
	for(int i=0;i<strlen(c);i++){
		switch(c[i]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				count++;
		}
	}
	printf("%d\n",count);
	return 0;
}