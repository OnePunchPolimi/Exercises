//scrivere un programma C che apre un file di testo "testo.txt" contenente parole ciascuna di al massimo 15 caratteri. Il programma chiede all'utente una sequenza 
//controlla di al massimo 26 caratteri distinti tra loro. Il programma stampa a video, per ogni carattere in controll, il numero di volte che e' presente nel file, 
//utillizando nella stampa righe distinte

//Ad esempio, se il file "testo.txt" contiene il testo:
//Il mio viaggio a Roma di Dicembre e' stato molto bello
//e la sequenze controlla e':azcm
// il programma stampa
//a:4
//z:0
//c:1
//m:4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 15
#define N 26

int main(){
	FILE *fp;
	char c[MAX_LEN];
	char controlla[N+1];
	int i,j,len_controlla,len_c;
	int *frequency;
	fp=fopen("Test2.txt","r");
	
	printf("inserisci stringa controllo:\n");
	scanf("%s",controlla);
	//printf("\n%s\n",controlla);
	len_controlla=strlen(controlla);
	frequency=(int*)malloc(sizeof(int)*len_controlla);
	
	for(j=0;j<len_controlla;j++){
		frequency[j]=0;
		//printf("\n%d\n",frequency[j]);
	}
	if(fp&&frequency){
		fscanf(fp,"%s",c);
		while(!feof(fp)){
			len_c=strlen(c);
			printf("%s ",c);
			for(j=0;j<len_controlla;j++){
				
				for(i=0;i<len_c;i++){
					
					if(c[i]==controlla[j]){
						frequency[j]++;
						//printf("%c:   %d\n",controlla[j],frequency[j]);
					}
				
				}
				
			}
			//printf("\n\n\n");
			fscanf(fp,"%s",c);
		}
		
		
	 	/*	len_c=strlen(c);
			
			for(j=0;j<len_controlla;j++){
				
				for(i=0;i<len_c;i++){
					
					if(c[i]==controlla[j]){
						frequency[j]++;
						printf("%c:   %d\n",controlla[j],frequency[j]);
					}
				
				}
				
			}
			printf("\n\n\n");
		
		*/
		
		
		
			for(i=0;i<len_controlla;i++){
				printf("%c: %d\n",controlla[i],frequency[i]);
			}
		printf("\n");
		fclose(fp);
	}
	else printf("errore apertura o errore malloc");
	

	
	return 0;
	
}


 
