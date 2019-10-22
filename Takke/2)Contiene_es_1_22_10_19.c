#include <stdio.h>
#define L1 10
#define L2 5

int main(){
	int arA[L1];//={3,4,66, 66,100,77,88,9,33,11};
	int arB[L2];//={77,88,9,33,11};
	int ris = 0;
	int i;
	int j;
	for(i=0;i<L1;i++){
		printf("Inserisci l'elemento %d di A : ",i);
		printf("\n");//Un a capo per rendere il programma più carino
		scanf("%d",&arA[i]);
	}
	for(i=0;i<L2;i++){
		printf("Inserisci l'elemento %d di B : ",i);
		printf("\n");
		scanf("%d",&arB[i]);
	}
	for(i=0;i<=L1-L2;i++){//Se fosse < e non <= non controllerebbe il valore in posizione 5 di arA
		if(arA[i]==arB[0]){
			ris = 1;
			for(j=1 ; j<L2 && ris; j++){//Se la Sequenza non è quella desiderata si esce subito dal loop
				if(arA[i+j] != arB[j]){//In questo modo i due indici si muovono parallelamente
					ris = 0;
				}
			}
			
		}
		if(ris){
			printf("Contiene\n");
			return 0;//Una volta trovato un risultato accettabile il programma termina
		}
	}
	return 0;
}