#include <stdio.h>
#define DIM 4

int main(){
	float mat[DIM][DIM];
	int i;
	int j;
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			printf("Colonna %d, Riga %d : ",i,j);
			scanf("%f",&mat[i][j]);
			printf("\n");
		}
	}
	for(i=0;i<DIM;i++){
		printf("%9.2f \n",mat[i][i]);//Il formato 9.2 rende i valori più leggibili, non è quindi obbligatorio
	}
	return 0;
}
