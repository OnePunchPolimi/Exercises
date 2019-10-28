#include<stdio.h>

#define N 4

int main(){
	int a[N][N];
	int aT[N][N];
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("Colonna %d, Riga %d : ",i,j);
			scanf("%d",&a[i][j]);
			printf("\n");
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			aT[j][i]=a[i][j];
		}
	}
	/*
	printf("Matrice: \n\n");//Da qui inizia il codice per il controllo
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("Trasposta: \n\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",aT[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
}
