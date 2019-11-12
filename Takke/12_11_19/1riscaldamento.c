#include<stdio.h>
#define N 10

int main(){
	int numeri[N];
	int x=-1;
	int s=0;
	int p=1;
	for(int i=0;i<N;i++){
		printf("%d: ",i);
		scanf("%d",&numeri[i]);
		printf("\n");
	}
	{
	printf("x: ");
	scanf("%d",&x);
	}while(x>9&&x>0);
	for(int i=0;i<x;i++){
		s+=numeri[i];
	}
	for(int i=x;i<N;i++){
		p*=numeri[i];
	}
	printf("SUM %d\n",s);
	printf("PROD %d\n",p);
	return 0;
}