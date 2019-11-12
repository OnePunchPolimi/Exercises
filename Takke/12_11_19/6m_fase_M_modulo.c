#include<stdio.h>
#include<math.h>
#define PI 3.141592654
#define N 2

typedef struct{
	float re;
	float im;
	float modulo;
	float fase;
}Complesso;

float cModulo(Complesso c){
		return sqrt(c.re*c.re+c.im*c.im);
		
}

float cFase(Complesso c){
	if(c.re==0){
		if(c.im>0){
			c.fase=PI/2;
		}
		else if(c.im<0){
			c.fase=3*PI/2;
		}
		else{
			return -1;
		}
	}
	else{
		if(c.re>0 && c.im>=0){
			c.fase=atan(c.im/c.re);
		}
		else if(c.re>0 && c.im<0){
			c.fase=atan(c.im/c.re)+2*PI;
		}
		else if(c.re<0){
			c.fase=atan(c.im/c.re)+PI;
		}
	}
	if(c.fase>2*PI)c.fase-=2*PI;
	else if(c.fase<0)c.fase+=2*PI;
	printf("%f\n",c.fase);
	return c.fase;
}
	

int main(){
	Complesso c[N];
	float max=-1;
	float min=7;
	int maxPos=-1;
	int minPos=-1;
	for(int i=0;i<N;i++){		
		printf("Reale %d: ",i);
		scanf("%f",&c[i].re);
		printf("\n");
		printf("Immaginario %d: ",i);
		scanf("%f",&c[i].im);
		printf("\n");
		c[i].modulo=cModulo(c[i]);
		c[i].fase=cFase(c[i]);
		if(c[i].modulo>max){
			max=c[i].modulo;
			maxPos=i;
		}
		if(c[i].fase<min){
			min=c[i].fase;
			minPos=i;
		}
	}
	printf("Max modulo=%f in pos: %d",max,maxPos);
	printf("Min fase=%f in pos: %d",min,minPos);
	
}