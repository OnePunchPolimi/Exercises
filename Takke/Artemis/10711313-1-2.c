#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 30
#define NWORDS 10
#define TOWIN 3

void artemisValigia();
int vocali(char[NWORDS][MAXLEN+1]);
int doppie(char[NWORDS][MAXLEN+1]);
int seguita(char[NWORDS][MAXLEN+1]);
int alternate(char[NWORDS][MAXLEN+1]);
int palindroma(char[NWORDS][MAXLEN+1]);
void toLowerCase(char[NWORDS][MAXLEN+1]);
int vocale(char);

int main(){
	artemisValigia();
	return 0;
}

void artemisValigia(){
	int criterio;
	int i;
	int ris;
	char parole[NWORDS][MAXLEN+1];
	printf("Input:\n");
	scanf("%d",&criterio);
	for(i=0;i<NWORDS;++i){
		scanf("%s",parole[i]);
	}
	toLowerCase(parole);//visto che nella consegna è esplicito che il gioco non è case sensitive porto tutte le stringhe in minuscolo per comodità
	/*
	for(i=0;i<NWORDS;++i){
		printf("%s\n",parole[i]);
	}//debug
	*/
	printf("Output:\n");
	switch(criterio){
		case 1:
			ris = vocali(parole);
			break;
		case 2:
			ris = doppie(parole);
			break;
		case 3:
			ris = seguita(parole);
			break;
		case 4:
			ris = alternate(parole);
			break;
		case 5:
			ris = palindroma(parole);
			break;
	}
	if(ris){
		printf("VINTO\n");
	}
	else{
		printf("PERSO\n");
	}
}

int vocali(char parole[NWORDS][MAXLEN+1]){
	int i,j=0;
	int count=0,vocali=0;
	for(i=0;i<NWORDS;++i,j=0){
		while(parole[i][j]!='\0'){
			if(vocale(parole[i][j])){
				++vocali;
			}
			++j;
		}
		if(vocali>=3){
			printf("%s ",parole[i]);
			++count;
		}
		vocali = 0;
	}
	return count>=3;
}

int doppie(char parole[NWORDS][MAXLEN+1]){
	int i,j=1;
	int count=0,doppie=0;
	char prev;
	for(i=0;i<NWORDS;++i,j=1){
		if(strlen(parole[i])>=4){//con la stringa lunga meno di 4 caratteri è inutile fare ulteriori controlli
			prev=parole[i][0];
			while(parole[i][j]!='\0'){
				//printf("doppia\n");//debug
				if(parole[i][j]==prev){
					++doppie;
					while(parole[i][j++]==prev){//non conto in realtà quante coppie di doppie si presentano, ma quanti caratteri uguali consecutivi
						++doppie;
						//printf("+");//debug
					}
				}				
				else{
					prev=parole[i][j++];
				}
			}
			if(doppie/2.0>=2){
				printf("%s ",parole[i]);
				++count;
			}
			doppie = 0;
		}
	}
	return count>=3;
}

int seguita(char parole[NWORDS][MAXLEN+1]){
	int i,j=0;
	int count=0,seguita=1;
	for(i=0;i<NWORDS;++i,j=0){
		while(parole[i][j]!='\0'){
			if(parole[i][j]=='m'){
				seguita = 0;
			}				
			if(parole[i][j]=='r'){
				seguita = 1;
			}
			++j;
		}
		if(seguita){
			printf("%s ",parole[i]);
			++count;
		}
		seguita = 1;
	}
	return count>=3;
}

int alternate(char parole[NWORDS][MAXLEN+1]){
	int i,j=1;
	int count=0,alt=1;
	int prev;
	for(i=0;i<NWORDS;++i,j=1){
		prev = vocale(parole[i][0]);
		while(parole[i][j]!='\0'&&alt){
			if(prev==vocale(parole[i][j])){//se prev==vocale(parole[i][j]) significa che sono susseguite 2 vocali o 2 consonanti 
				//printf("%s in pos %d con %c e prev %d\n",parole[i],j,parole[i][j],prev);//debug 
				alt=0;
			}
			else{
				prev=!prev;//il nuovo prev sarà sempre diverso dal precedente finchè la parola alterna vocali e consonanti
			}
			++j;
		}
		if(alt){
			printf("%s ",parole[i]);
			++count;
		}
		alt = 1;
	}
	return count>=3;
}

int palindroma(char parole[NWORDS][MAXLEN+1]){
	int i,j=0;
	int count=0,palindroma=1;
	int len;
	for(i=0;i<NWORDS;++i,j=0){
		len = strlen(parole[i]);
		while(parole[i][j]!='\0'&&palindroma&&j<=len/2){//è inutile controllare oltre la metà della parola, perchè se non fosse palindroma sarebbe già uscita dal ciclo
			if(parole[i][j]!=parole[i][len-j-1]){
				palindroma=0;
			}
			++j;
		}
		if(palindroma){
			printf("%s ",parole[i]);
			++count;
		}
		palindroma = 1;
	}
	return count>=3;
}

int vocale(char c){
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

void toLowerCase(char parole[NWORDS][MAXLEN+1]){
	int i,j=0;
	for(i=0;i<NWORDS;++i,j=0){
		while(parole[i][j]!='\0'){
			parole[i][j] = tolower(parole[i][j]);
			++j;
		}
	}
}