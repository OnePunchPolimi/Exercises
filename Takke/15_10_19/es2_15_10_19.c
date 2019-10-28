/**
 *Dato un intero rappresentante l'anno definire se è bisestile(divisibile per 4, esclusi i divisibili per 100 con eccezione i divisibili per 400)
 */

#include <stdio.h>
int main(){
	int anno;
	scanf("%d",&anno);
	if(anno%4 == 0){
		if(anno%100 == 0){
			if(anno%400 == 0){
				printf("L'anno è bisestile\n");
			}
			else {
				printf("L'anno non è bisestile\n");
			}
		}
		else{
			printf("L'anno è bisestile\n");
		}
	}
	else {
		printf("L'anno non è bisestile\n");
	}
	return 0;
}
