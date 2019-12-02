#include<stdio.h>
#include<math.h>

typedef struct complesso{
	float re;
	float im;
	float modulo;
	float fase;
}Complesso;

int main(){
	Complesso c1;
	Complesso c2;
	printf("Reale1: ");
	scanf("%f",&c1.re);
	printf("\n");
	printf("Reale2: ");
	scanf("%f",&c2.re);
	printf("\n");
		
	printf("Im1: ");
	scanf("%f",&c1.im);
	printf("\n");
	printf("Im2: ");
	scanf("%f",&c2.im);
	printf("\n");


	printf("somma:%9.2f + i%9.2f\n",c1.re+c2.re,c1.im+c2.im);
	if(c1.re*c2.re>0){
		if(c1.im==0&&c2.im==0){
			printf("fase uguale");
		}
		else if(c1.re/c1.im==c2.re/c2.im){
			printf("fase uguale");
		}
		else{
			printf("fase diversa");
		}
	}
	else{
		printf("fase diversa");
	}
	printf("\n");
}