#include<stdio.h>

#define L 50

int main(){
	char romano[L+1];
	int ris=0;
	printf("romano: ");
	scanf("%s",romano);
	printf("\n");
	for(int i=0;romano[i]!='\0';i++){
		switch(romano[i]){
			case 'I':
				++ris;
				break;
			case 'V':
				ris+=5;
				break;
			case 'X':
				ris+=10;
				break;
			case 'L':
				ris+=50;
				break;
			case 'C':
				ris+=100;
				break;
			case 'D':
				ris+=500;
				break;
			case 'M':
				ris+=1000;
				break;
		}
	}
	printf("ris: %d\n",ris);
	return 0;
}