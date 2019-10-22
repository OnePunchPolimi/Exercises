#include <stdio.h>
#define N 4

int main(){
	int matrix[N][N];
	int massimi[N][N]={0};
	int i,j,c,r;
	int max;//This is used as boolean
	//input
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("Colonna %d, Riga %d di A: ",i,j);
			scanf("%d",&matrix[i][j]);
			printf("\n");
		}
	}
	//fine input
	for(i=0;i<N;i++){//Stampa la matrice di input
		for(j=0;j<N;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			max=1;
			c=i;
			r=j;
			{//Controlli sulle posizioni adiacenti
				if(matrix[(c+1)%N][r]>matrix[c][r]){max=0;}
				if(matrix[c][(r+1)%N]>matrix[c][r]){max=0;}
				if(matrix[c==0?N-1:c-1][r]>matrix[c][r]){max=0;}//Uso di peratore ternario per non alternare i valori di c e r
				if(matrix[c][r==0?N-1:r-1]>matrix[c][r]){max=0;}
			}
			if(max){
				printf("Massimo locale: %d\n",matrix[i][j]);
				massimi[i][j]=1;
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(massimi[i][j]==1){
				matrix[i][j]=0;
			}
		}
	}
	
	for(i=0;i<N;i++){//Stampa la matrice lavorata
		for(j=0;j<N;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
