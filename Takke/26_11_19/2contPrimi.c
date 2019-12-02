#include <stdio.h>

#define N 1
#define M 10

int primo(int,int);

int main(){
	printf("%d\n",primo(N,M));
	return 0;
}

int quantiPrimo(int n,int m){//Non trovo giusto riutilizzare la funzione dell'es1 in quanto la consegna diceva esplicitamente di modificare la funzione, non riciclarla
	int j,i;
	int ris=0;
	int primo=1;
	for(i=n;i<=m;i++){
		if(i<1)primo=0;
		for(j=2;j<=i/2&&primo;++j){
			if(i%j==0){
				primo=0;
			}
		}
		if(primo){
			++ris;
		}
		primo=1;
	}
	return ris;
}