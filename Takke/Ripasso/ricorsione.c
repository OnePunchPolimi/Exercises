#include <stdio.h>
#include <stdlib.h>

void somme_prefisse_ric(int* b,int a[],int n){
	if(n>1){
		somme_prefisse_ric(b,a,n-1);
		b[n-1]=a[n-1]+b[n-2];
	}
	if(n==1){
		b[0]=a[0];
	}
}

int* somme_prefisse(int a[],int n){
	int* b=(int*)malloc(sizeof(int)*n);
	somme_prefisse_ric(b,a,n);
	return b;
}



int main(){
	int a[10]={1,2,3,4,5,6,3,2,1,1};
	int* b=somme_prefisse(a,10);
	for(int i=0;i<10;i++){
		printf("%d : %d\n",i,b[i]);
	}
	return 0;
}