#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 100

typedef struct Cell{
	char val;
	int checked;
	struct Cell* w;
	struct Cell* a;
	struct Cell* s;
	struct Cell* d;
}Cell;

typedef struct Grid{
	int c;
	int r;
	struct Cell* head;
}Grid;

void show();
void fill(char s[],Cell* new);
void fill2(char s[],Cell* new, Cell* curr);
int checkRoot(char s[]);
int countChimney();
int countChecked();
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
		if(!feof(file) && strcmp(string,"STOP")){
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
			else{
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
		last->d = (Cell*)malloc(sizeof(Cell));
		right = last->d;
		right->a = last;
		right->val = s[i];
		last = right;
		right = right->d;
	}
	return;
}
void fill2(char s[],Cell* new, Cell* curr){
	int length = strlen(s);
	int i;
	Cell* last = new;
	Cell* now;
	Cell* prec = curr;
	if(length>0){
		new->val=s[0];
		new->w=prec;
		prec=prec->d;
	}
	for(i=1;i<length;++i){
		last->d = (Cell*)malloc(sizeof(Cell));
		now = last->d;
		now->a = last;
		now->val = s[i];
		now->w=prec;
		prec->s=now;
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
		if(current==NULL){
			return 0;
		}
		//printf("%c",current->val);//debug
		switch(current->val){
			case 'X':
			current->checked=1;
			break;
			case 'O':
			return 0;
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