#include <stdio.h>
#include <string.h>
#define R 5
#define C 6
#define LEN 30
#define MAX 30

int orizzontale(char[C][R],char[],int,int);//char *
int verticale(char[C][R],char[],int,int);
int diagonale(char[C][R],char[],int,int);
int noFine(char[]);
int ctrl(char[C][R],char[]);

void inPuzzle(char[C][R]);
void artemisPuzzle();

int main(){
	artemisPuzzle();
	return 0;
}

void artemisPuzzle(){
	char puzzle[C][R];
	int i,j;
	printf("Input:\n");
	char parola[C+1];//impongo la lunghezza massima della singola parola a C+1 perchè è la dimensione massima che la parola potrà prendere spazio nella matrice con aggiunta del carattere terminatore
	int ris[MAX];	//impongo un numero massimo di parole inseribili a 30, non avrei mai voluto fare una cosa simile
					//ma è stato risposto che l'output richiesto deve essere esattamente come dato nell'esempio
					//quindi non ho voluto rischiare di sbagliare o di perdere troppo tempo per elaborare un algoritmo decente 
					//per dare in output SU RIGA SINGOLA TUTTI I RISULTATI COME L'ESEMPIO MOSTRA 
	int cont=0;//contatore di parole inserite
	inPuzzle(puzzle);
	
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			printf("%c",puzzle[j][i]);
		}
		printf("\n");
	}//debug
	
	while(noFine(parola)){//A ogni posizione di ris sarà assegnato un risultato
		ris[cont++]=ctrl(puzzle,parola);
	}
	printf("Output: \n");
	for(i=0;i<cont;++i){//output dei risultati
		printf(ris[i]?"PRESENTE ":"ASSENTE ");
	}
	printf("\n");
}

void inPuzzle(char puzzle[C][R] ){//Inizializazione del puzzle
	char stringa[LEN+1];
	int i,j;
	scanf("%s",stringa);
	for(i=0;i<R;++i){
		for(j=0;j<C;++j){
			puzzle[j][i]=stringa[i*C+j];
		}
	}
}

int noFine(char parola[]){//Acquisizione della parola e controllo della FINE
	scanf("%s",parola);
	if(parola[0]=='F' && parola[1]=='I' && parola[2]=='N' && parola[3]=='E' && parola[4]=='\0')return 0;
	return 1;
}

int ctrl(char puzzle[C][R],char parola[]){//funzione di controllo generale
	int i,j;
	for(i=0;i<C;++i){
		for(j=0;j<R;++j){
			if(puzzle[i][j]==parola[0]){//controlla per ogni lettera se è presente la parola in orizzontale verticale o diagonale a partire da essa
				if(orizzontale(puzzle,parola,i,j) || verticale(puzzle,parola,i,j) || diagonale(puzzle,parola,i,j)){
					return 1;
				}
			}
		}
	}
	return 0;
}

int orizzontale(char puzzle[C][R],char parola[],int c,int r){
	int i=0;
	int len=strlen(parola); 
	if(c+len>C)return 0;//Se la parola è troppo lunga e non può essere quindi contenuta nella matrice a partire dalle coordinate date return 0
	while(parola[++i]!='\0'){//il primo carattere viene saltato perchè uguale per condizione di entrata alla funzione
		if(puzzle[c+i][r]!=parola[i])return 0;
		//printf("%c%c ",parola[i],puzzle[c+i][r]);//debug
	}
	return 1;
}

int verticale(char puzzle[C][R],char parola[],int c,int r){
	int i=0;
	int len=strlen(parola); 
	if(r+len>R)return 0;//Se la parola è troppo lunga e non può essere quindi contenuta nella matrice a partire dalle coordinate date return 0
	while(parola[++i]!='\0'){//il primo carattere viene saltato perchè uguale per condizione di entrata alla funzione
		if(puzzle[c][r+i]!=parola[i])return 0;
	}
	return 1; 
}

int diagonale(char puzzle[C][R],char parola[],int c,int r){
	int i=0;
	int len=strlen(parola); 
	if(c+len>C)return 0;//Se la parola è troppo lunga e non può essere quindi contenuta nella matrice a partire dalle coordinate date return 0
	if(r+len>R)return 0;//Se la parola è troppo lunga e non può essere quindi contenuta nella matrice a partire dalle coordinate date return 0
	while(parola[++i]!='\0'){//il primo carattere viene saltato perchè uguale per condizione di entrata alla funzione
		if(puzzle[c+i][r+i]!=parola[i])return 0;
	}
	return 1;
}




