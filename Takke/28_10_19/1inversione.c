#include <stdio.h>

int main(){
	char c = 0;
	printf("%c",c);
	int n;
	int ris = 0;
	printf("Inserisci il numero: ");
	scanf("%d",&n);
	while(n>0){
		ris = ris*10 + n%10;
		n/=10;
	}
	printf("Il numero invertito è :%d \n",ris);
	return 0;
}
	