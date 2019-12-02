#include <stdio.h>

#define N 100

int leggiStringa(char *s);

int main(){
	char stringa[N];
	printf("stringa: ");
	printf("%d",leggiStringa(stringa));
	printf("%s",stringa);
	return 0;
}

int leggiStringa(char *s){
	int i;
	char c;
	for(i=0,c=getchar();c!='\n';++i,c=getchar()){
		s[i]=c;
	}
	s[i]='\0';
	return i;
}