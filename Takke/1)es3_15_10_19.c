#include <stdio.h>

/**
 *Dati 2 interi in input, restituire i divisori comuni(escluso 1)
 */
int main(){
	int n1;
	int n2;
	int div;
	printf("Inserisci i numeri :");
	scanf("%d %d",&n1,&n2);
	printf("\n inseriti n1=%d e n2=%d \n",n1,n2);
	printf("Divisori comuni: ");
	for(div=2;div<=n1&&div<=n2;div++){//div = 0 会bug，div = 1会把1当成divisore
		if(n1%div==0 && n2%div==0){
			printf("%d ",div);
		}
	}
	printf("\n");
	return 0;
}
