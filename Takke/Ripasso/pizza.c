//pizza:codice,nome[30+1],listaIngredienti[10]
//ingrediente: codiceNumerico, nome[50+1]

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NP 30
#define NI 50
#define TERM 1

char nomiPizze[10][NP+TERM]={"margherita","marinara","prosciutto","patate","funghi","formaggi","rossa","bianca","girasole","diavola"};
char nomiIngredienti[5][NI+TERM]={"pomodoro","mozzarella","prosciutto","patate","salame"};
typedef struct ingrediente{
	int codiceNumerico;
	char nome[NI+TERM];
	struct ingrediente * next;
}ingrediente;

typedef struct lista{
	struct ingrediente * head;
	int leng;
}lista;

typedef struct pizza{
	int codice;
	char nome[NP+TERM];
	struct lista ingredienti;
	int costo;
}pizza;

void sottoprogramma(pizza p[],int dimensione,int n){
	int i;
	for(i=0;i<dimensione;i++){
		if(p[i].ingredienti.leng<n){
			printf("%s\n",p[i].nome);
		}
	}
}

int main(){
	int n=3;
	int dim=10;
	int i,j,l,randomN,randomIng;
	srand((unsigned)time(NULL));
	ingrediente * now;
	pizza p[dim];
	for(i=0;i<dim;i++){
		p[i].codice=i;
		strcpy(p[i].nome,nomiPizze[i]);
		printf("nome: %s ",p[i].nome);
		p[i].ingredienti.leng=0;
		p[i].ingredienti.head=(ingrediente*)malloc(sizeof(ingrediente));
		now=p[i].ingredienti.head;
		if(now!=NULL){
			now->next=NULL;
			for(j=0 , randomN = rand()%5; j<randomN; j++){
				randomIng=rand()%5;
				now->codiceNumerico=randomIng;
				strcpy(now->nome,nomiIngredienti[randomIng]);
				printf(" %s ",now->nome);
				p[i].ingredienti.leng++;
			}
			printf("\n");
		}
		else{
			printf("Error in malloc\n");
		}
	}
	sottoprogramma(p,dim,n);
	return 0;
}
	




