#include <stdio.h>

#define N 10

int isPerfetto(int);

int main(){
	int array[N];
	int massimo = 0;
	for(int i=0; i<N;i++){
		printf("inserire il valore %d dell'array :",i);
		scanf("%d",&array[i]);
	}
	for(int i=0; i<N;i++){
		if(isPerfetto(array[i])){
			massimo = massimo > array[i] ? massimo : array[i];// Operatore ternario ( condizione ? seVero : seFalso )
		}
	}
	if(massimo){
		printf("Il perfetto massimo è : %d \n",massimo);
	}
	else {
		printf("Non sono stati inseriti numeri perfetti \n");
	}
	return 0;
}

int isPerfetto(int n){
	int somma=0;
	for(int i=1; i<n ; i++){//Si inizia da 1 per evitare errori
		if(n%i==0){
			somma+=i;
		}
	}
	return somma == n;
}