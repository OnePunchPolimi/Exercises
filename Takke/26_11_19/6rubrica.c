#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h>
#include <time.h>

#define LEN 30
#define LDATA 10
#define CIFRE 10
#define CONT_MAX 100
typedef struct rubrica{
	char cognome[LEN+1];
	char nome[LEN+1];
	char dataNascita[LDATA+1];
	int eta;
	char numero[CIFRE+1];
}Rubrica;

int help();
int insert();
int delete();
int list();
int search();
int stat();
void randomFill();

Rubrica rub[CONT_MAX];
int contatti;

int main(){
	char c[LEN]="1";
	int wrong=1;
	randomFill();
	while(c[0]!='0'){
		printf("Si inserisca il comando(h to help)\n");
		do{
			scanf("%s",c);
			c[0]=tolower(c[0]);
			wrong=0;
			switch(c[0]){
				case 'h':
					help();
					break;
				case 'i':
					insert();
					break;
				case 'c':
					delete();
					break;
				case 'e':
					list();
					break;
				case 'r':
					search();
					break;
				case 's':
					stat();
					break;
				case '0':
					break;
				default:
					wrong = 1;
					printf("Comando non esistente, reinserire il comando: ");
			}
		}while(wrong);
	}
}

int help(){
	printf("Sono elencati i comandi accettati dal programma.\nIl programma accetta una qualsiasi stringa come imput contenente in prima posizione:\nh help\ni inserimento\nc cancellazione\ne elenco\nr ricerca\ns statistiche\n");
	return 0;
}

int insert(){
	printf("nome:\n");
	scanf("%s",rub[contatti].nome);
	printf("cognome:\n");
	scanf("%s",rub[contatti].cognome);
	printf("dataNascita:\n");
	scanf("%s",rub[contatti].dataNascita);
	printf("numero:\n");
	scanf("%s",rub[contatti].numero);
	++contatti;
	return 0;
}

int delete(){
	printf("Numero del contatto da cancellare:");
	int i=0;
	int canc=0;
	char vittima[CIFRE+1];
	scanf("%s",vittima);
	while(i<contatti){
		if(!strcmp(rub[i].numero,vittima)){
			for(int h=i;h<contatti-1;h++){
				rub[h]=rub[h+1];
			}
			--contatti;
			printf("Numero cancellato\n");
			++canc;
		}
		++i;
	}
	if(canc==0){
		printf("Numero non presente\n");
	}
	return canc;
}

int list(){
	int i,j;
	for(i=0;i<contatti;++i){
		printf("%d",i+1);
		for(j=1000;j>i+1;j/=10){
			printf(" ");
		}
		printf("%s",rub[i].cognome);
		for(j=0;j<LEN-strlen(rub[i].cognome);j++){
			printf(" ");
		}
		printf("%s",rub[i].nome);
		for(j=0;j<LEN-strlen(rub[i].nome);j++){
			printf(" ");
		}
		printf("%s ",rub[i].dataNascita);
		printf("%d",rub[i].eta);
		for(j=1000;j>rub[i].eta;j/=10){
			printf(" ");
		}
		printf("%s",rub[i].numero);
		printf("\n");
	}
	return 0;
}

int search(){
	printf("Numero del contatto da cercare:");
	int i=0,j;
	char vittima[CIFRE+1];
	scanf("%s",vittima);
	while(i<contatti){
		if(!strcmp(rub[i].numero,vittima)){
			printf("%d",i+1);
			for(j=1000;j>i+1;j/=10){
				printf(" ");
			}
			printf("%s",rub[i].cognome);
			for(j=0;j<LEN-strlen(rub[i].cognome);j++){
				printf(" ");
			}
			printf("%s",rub[i].nome);
			for(j=0;j<LEN-strlen(rub[i].nome);j++){
				printf(" ");
			}
			printf("%s ",rub[i].dataNascita);
			printf("%d",rub[i].eta);
			for(j=1000;j>rub[i].eta;j/=10){
				printf(" ");
			}
			printf("%s",rub[i].numero);
			printf("\n");
			return 0;
		}
		++i;
	}
	return 1;
}

int stat(){
	int media;
	int mediana;
	for(int i=0;i<contatti;++i){
		media+=rub[i].eta;
	}
	printf("L'età media è: %d\n",media/contatti);
	return 0;
}

void randomFill(){
	srand((unsigned)time(NULL));
	contatti=rand()%100;
	for(int i=0;i<contatti;i++){
		int len =rand()%30;
		for(int j=0;j<len;j++){
			rub[i].cognome[j]=rand()%26+'a';
		}
		rub[i].cognome[len]='\0';
		len = rand()%30;
		for(int j=0;j<len;j++){
			rub[i].nome[j]=rand()%26+'a';
		}
		rub[i].nome[len]='\0';
		for(int j=0;j<CIFRE;j++){
			rub[i].numero[j]=rand()%10+'0';
		}
		stpcpy(rub[i].dataNascita,"01/01/2000");
		rub[i].eta=1+rand()%100;
	}
}