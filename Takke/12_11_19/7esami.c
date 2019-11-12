#include<stdio.h>

#define L 50
#define MAX 5 //10
#define ES 3

typedef struct{
	char nome[L+1];
	int voto;
}Exam;

typedef struct{
	int codice;
	Exam esami[ES];
	int num;
}Student;

int main(){
	int i,e;
	int codice;
	Student studenti[MAX];
	for( i=0;i<MAX;i++){
		printf("codice persona %d: ",i);
		scanf("%d",%studenti[i].codice);
		printf("\n");
		e=-1;
		while(++e<ES){
			printf("nome esame: ");
			scanf("%s",studenti.esami[e].nome);
			printf("\n");
			{
				printf("voto esame: ");
				scanf("%d",&studenti.esami[e].voto);
				printf("\n");
			}while(studenti.esami[e].voto<=30&&studenti.esami[e].voto>=0);
		}
	}
	printf("Codice: ");
	scanf("%d",&codice);
	printf("\n");
	for( i=0;i<MAX;i++){
		if(studenti[i].codice=codice){
			for(e=0;e<ES;i++){
				printf("Esame: %s  voto: %d",studente[i].esami[e].nome,studente[i].esami[e].voto);
			}
		}
	}
	return 0;
}