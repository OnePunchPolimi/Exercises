#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 100

typedef struct Cell{//le direzioni corrispondono alla disposizione wasd della tastiera
	char val;
	int checked;
	struct Cell* w;
	struct Cell* a;
	struct Cell* s;
	struct Cell* d;
}Cell;

typedef struct Grid{
	struct Cell* head;
}Grid;

void show();//funzione per puro debug
void fill(char s[],Cell* new);//riempimento della prima riga della griglia
void fill2(char s[],Cell* new, Cell* curr);//riempimento delle altre righe della griglia
int checkRoot(char s[]);//controllo su un percorso fornito 0 se il percorso è errato, 1 in caso opposto
int countChimney();//conteggio del numero di camini
int countChecked();//conteggio del numero di camini visitati alla fine del percorso e azzeramento dei valori
Grid grid;
int main(int argc ,char* argv[]){
	int end=0;
	FILE* file;
	char string[L];
	Cell* curr;
	char elfo[L];
	/*//debug
	file = fopen(argv[1],"r");
	while(!feof(file)){
		fscanf(file,"%s",string);
		printf("%s\n",string);
	}
	*/
	grid.head=(Cell*)malloc(sizeof(Cell));
	curr=grid.head;
	file = fopen(argv[1],"r");
	
	if(file==NULL){
		printf("%s\n",argv[1]);
		printf("Errore di apertura file\n");
		return 0;
	}
	else{
		fscanf(file,"%s",string);
		if(!feof(file) && strcmp(string,"STOP")){//riempimento della prima riga e controllo sui casi limite
			fill(string,curr);
		}
		else{
			end = 1;
		}
		while(!feof(file) && !end){
			fscanf(file,"%s",string);
			if(strcmp(string,"STOP")){
				curr->s=(Cell*)malloc(sizeof(Cell));
				fill2(string,curr->s,curr);
				curr=curr->s;
			}
			else{//uscita dal ciclo con uso di un flag
				end = 1;
			}
		}
		while(!feof(file)){
			fscanf(file,"%s",elfo);
			fscanf(file,"%s",string);
			if(checkRoot(string)){
				printf("%s SI\n",elfo);
			}
			else{
				printf("%s NO\n",elfo);
			}
		}
		fclose(file);
	}
	//show();//debug
	return 0;
}

void show(){
	Cell* t = grid.head;
	Cell* temp;
	while(t!=NULL){
		temp = t;
		while(temp!=NULL){
			printf("%c",temp->val);
			temp=temp->d;
		}
		printf("\n");
		t=t->s;
	}
}

void fill(char s[],Cell* new){
	int length = strlen(s);
	int i;
	Cell* last = new;
	Cell* right;
	if(length>0){
		new->val=s[0];
	}
	for(i=1;i<length;++i){
		//creazione della nuova cella
		last->d = (Cell*)malloc(sizeof(Cell));
		right = last->d;
		//scambio di puntatori per ottenere una griglia ben collegata
		right->a = last;
		//inserimento del valore
		right->val = s[i];
		//avanzamento dei posti
		last = right;
		right = right->d;
	}
	return;
}
void fill2(char s[],Cell* new, Cell* curr){
	int length = strlen(s);
	int i;
	Cell* last = new;//rappresenta l'ultima cella editata
	Cell* now;//cella attuale
	Cell* prec = curr;//rappresenta la cella corrispondente della riga precedente
	if(length>0){
		new->val=s[0];
		new->w=prec;
		prec=prec->d;
	}
	for(i=1;i<length;++i){
		//creazione della nuova cella
		last->d = (Cell*)malloc(sizeof(Cell));
		now = last->d;
		//scambio di puntatori per ottenere una griglia ben collegata
		now->a = last;
		now->w = prec;
		prec->s = now;
		//inserimento del valore
		now->val = s[i];
		//avanzamento dei posti
		prec=prec->d;
		last = now;
		now = now->a;
	}
}

int checkRoot(char s[]){
	int length,i,blocked=0,chimney;
	Cell* current = grid.head;
	chimney=countChimney();
	for(i=0,length=strlen(s);i<length && !blocked;++i){
		switch(s[i]){
			case 'N':
			current=current->w;
			break;
			case 'S':
			current=current->s;
			break;
			case 'E':
			current=current->d;
			break;
			case 'O':
			current=current->a;
			break;
			default:
			printf("Carattere non valido\n");
			return 0;
		}
		if(current==NULL){//controllo sui margini della griglia
			return 0;
		}
		//printf("%c",current->val);//debug
		switch(current->val){//controllo sul valore corrente
			case 'X':
			current->checked=1;
			break;
			case 'O':
			return 0;//uscita in caso di ostacolo
		}
	}
	return chimney==countChecked();
}

int countChecked(){
	Cell* t = grid.head;
	Cell* temp;
	int ris=0;
	while(t!=NULL){
		temp = t;
		while(temp!=NULL){
			if(temp->checked){
				++ris;
				temp->checked=0;
			}
			temp=temp->d;
		}
		t=t->s;
	}
	//printf("checked %d\n",ris);//debug
	return ris;
}

int countChimney(){
	Cell* t = grid.head;
	Cell* temp;
	int ris=0;
	while(t!=NULL){
		temp = t;
		while(temp!=NULL){
			if(temp->val=='X')++ris;
			temp=temp->d;
		}
		t=t->s;
	}
	//printf("chimney %d\n",ris);//debug
	return ris;
}