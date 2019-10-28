#include <stdio.h>

#define DIM 4
int main(){
	int a[DIM][DIM];//nomi tanto significativi(???)
	int b[DIM][DIM];
	int i,j;
	//input
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			printf("Colonna %d, Riga %d di A: ",i,j);
			scanf("%d",&a[i][j]);
			printf("\n");
		}
	}
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			printf("Colonna %d, Riga %d di B: ",i,j);
			scanf("%d",&b[i][j]);
			printf("\n");
		}
	}
	//fine input
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			if(a[i][j]==b[i][j]){
				printf("(%d,%d)",i,j);
			}
		}
	}
	return 0;
}
