#include <stdio.h>

#define MAX 50

int main(){
	int i,j,found,ris;
	i = ris = 0;//assegnazioni concatenate(solo per mostrare l'esistenza di questa possibilità, non che sia veramente utile)
	char s1[MAX];
	char s2[MAX];
	printf("S1: ");
	scanf("%s",s1);
	printf("S2: ");
	scanf("%s",s2);
	while(s1[i]!='\0'){
		if(s1[i]==s2[0]){
			j=1;
			found = 1;
			while(s2[j]!='\0'){
				if(s1[i+j]!=s2[j]){
					found = 0;
				}
				++j;
			}
			if(found){
				++ris;
			}
		}
		++i;
	}
	if(ris){
		printf("S2 è contenuto in S1 %d volte.",ris);
	}
	else{
		printf("S2 non è contenuto in S1.");
	}
	return 0;
}