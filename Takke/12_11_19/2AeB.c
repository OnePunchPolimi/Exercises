#include<stdio.h>
#define N 5
int main(){
	int A[N];
	int B[N];
	for(int i=0;i<N;i++){
		printf("A%d: ",i);
		scanf("%d",&A[i]);
		printf("\n");
	}
	for(int i=0;i<N;i++){
		printf("B%d: ",i);
		scanf("%d",&B[i]);
		printf("\n");
	}
	for(int i=0;i<N;i++){
		printf("%d\n%d\n",A[i],B[N-i-1]);
	}
		
	return 0;
}