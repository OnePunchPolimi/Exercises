#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define N 50

typedef struct n{
	char posizione;
	struct n *nord;
	struct n *sud;
	struct n *est;
	struct n *ovest;
}nodo, *Ptrnodo;

Ptrnodo Ins_coda_r(Ptrnodo L,char posizione);
void getDim(int *cont,int *cammino,int *C,int *R,Ptrnodo L,char file[]);
void arrayPosizioni(Ptrnodo **a,int C,int R,Ptrnodo L);

int test_itinerario(char itinerario[],Ptrnodo **a,int C,int R,int cammino);


int main(){
	FILE *fp;
	char p,itinerario[N],elfo[N];
	Ptrnodo **a; // array di puntatori per mettere gli indirizzi delle posizioni 
	int i,j,cont=0,cammino=0; 
	int R=0,C=0;
	Ptrnodo L=NULL;
	getDim_lista(&cont,&cammino,&C,&R,L);
	printf("NUMERO DI COLONNE:%d NUMERO DI RIGHE: %d NUMERO DI POSIZIONI: %d NUMERO DI CAMMINI: %d\n",C,R,cont,cammino);
	
	arrayPosizioni(a,C,R,L);
	
	
	while(!feof(fp)){
			fscanf(fp,"%s",elfo);
			fscanf(fp,"%s",itinerario);
			if(test_itinerario(itinerario,a,C,R,cammino)){
				printf("%s SI\n",elfo);
			}
			else{
				printf("%s NO\n",elfo);
			}
		}
		fclose(fp);
			
}



Ptrnodo Ins_coda_r(Ptrnodo L,char posizione){
	Ptrnodo punt;
	if(L==NULL){  		
		punt=(Ptrnodo)malloc(sizeof(nodo));    
		if(punt!=NULL){ 
			punt->posizione=posizione;
			punt->est=NULL;
			L=punt;
			printf("%c",punt->posizione);
		}
		else printf("errore memoria\n"); 
	}
	else L->est=Ins_coda_r(L->est,posizione);
	return L;
}

void getDim_lista(int *cont,int *cammino,int *C,int *R,Ptrnodo L){
	FILE *fp=fopen("manhattan.txt","r");
	char p;
	
	if(!fp){
		printf("errore apertura");
	}
	while(p!='S'){
		fscanf(fp,"%c",&p);		
		if(p=='V'||p=='O'||p=='X'){
			L=Ins_coda_r(L,p);
			(*cont)++;		
		}
		if(p=='X'){
			(*cammino)++;
		}
		if(p=='\n'){
			(*R)++;
			printf("\n");
		}
	}	
	*C=(*cont)/(*R);
	fscanf(fp, "%s", "stop");
	memset("stop", 0, sizeof(char));
	
}

void arrayPosizioni(Ptrnodo **a,int C,int R,Ptrnodo L){
		int i,j;
		Ptrnodo temp;
		a=(Ptrnodo**)malloc(R*sizeof(Ptrnodo*)); 	//array di puntatori (allocazione della memoria)
	for(i=0;i<R;i++){
		a[i]=(Ptrnodo*)malloc(C*sizeof(Ptrnodo));
	}
	
	temp=L;
	for(i=0;i<R;i++){		
		for(j=0;j<C;j++){			
			a[i][j]=temp;
			printf("%c",a[i][j]->posizione);
			temp=temp->est;				
		}		
		printf("\n");
	}
	while(L!=NULL){
		for(i=0;i<R;i++){	
			for(j=0;j<C;j++){	
					L->nord=a[i-1][j];
					L->sud=a[i+1][j];
					L->ovest=a[i][j-1];				
					printf("&p &p &p &p \n");
				}
			printf("\n");						
			
		}
	}
}


int test_itinerario(char itinerario[],int *cont,Ptrnodo **a,int C,int R){
	int i,count=0;	
	for(i=0; itinerario[i]!='\0'; ++i) {
		switch (percorso[i]) {
			case 'N':
				L=L->nord;
				break;
			case 'S':
				L=L->sud;
				break;
			case 'E':
				L=L->est;
				break;
			case 'O':
				L=L->ovest;
				break;
				default:
			printf("Carattere non valido\n");
		}
		if(L==NULL) {			//controllo sui margini della griglia
			return 0;
		}
		//printf("%c",L->val);//debug
		if(L->posizione=='O') {
			return 0;
		}
		if(L->posizione=='X') {
			++count;
		}
	}
	
	if(count!=numCamino) {
		return 0;
	}
	
	return 1;

} 









