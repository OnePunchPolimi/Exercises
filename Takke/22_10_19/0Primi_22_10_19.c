#include <stdio.h>

int main(){
	int input;
	int n;
	int end;
	scanf("%d",&input);
	end=input/2;//basterebbe arrivare fino alla radice del numero, ma bisognerebbe includere Math.h
	for(n=2; n<=end ; n++){
		if(input%n==0){
			printf("%d non è un numero primo \n", input);
			return 0;
		}
	}
	printf("%d è un numero primo \n", input);
	return 0;
}
