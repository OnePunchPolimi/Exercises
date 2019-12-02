#include <stdio.h>

#define N 100

int primo(int);

int main(){
	for(int i=0;i<N;i++){
		printf("%d è %d\n",i,primo(i));
	}
	return 0;
}

int primo(int i){
	int j;
	if(i<1)return 0;
	for(j=2;j<=i/2;++j){
		if(i%j==0)return 0;
	}
	return 1;
}