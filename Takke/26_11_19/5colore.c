#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 100

#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define DEF "\033[0m;"

void toLowerCase(char parola[]);

void nomeColorato(char colore[],char frase[]){
	toLowerCase(colore);
	if(!strcmp(colore,"red")){				
		printf(RED);
		printf("%s\n",frase);
		printf(DEF);
	}
	else if(!strcmp(colore,"blue")){
		printf(BLUE);
		printf("%s\n",frase);
		printf(DEF);
	}
	else if(!strcmp(colore,"green")){				
		printf(GREEN);
		printf("%s\n",frase);
		printf(DEF);
	}
}

int main(){
	char colore[N];
	char nome[N];
	scanf("%s",colore);
	scanf("%s",nome);
	nomeColorato(colore,nome);
	return 0;
}


void toLowerCase(char parola[]){
	for(int i=0;parola[i]!='\0';++i)parola[i]=tolower(parola[i]);
}