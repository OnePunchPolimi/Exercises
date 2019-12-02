#include <stdio.h>

typedef struct complex{
	float re;
	float im;
	float modulo;
	float fase;
}Complex;

int isOrigin(struct complex n);

int main(){
	Complex n;
	n.re=2;
	n.im=0;
	printf("%d\n",isOrigin(n));
	return 0;
}

int isOrigin(struct complex n){
	return n.re==0 && n.im==0;
}