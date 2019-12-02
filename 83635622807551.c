#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 30
#define M 10
typedef struct {
     char a[N+1];
    }parola;
void converte(char a[]);
bool f1(char a[],int dim);
bool f2(char a[],int dim);
bool f3(char a[],int dim);
bool f4(char a[],int dim);
bool f5(char a[],int dim);

int main(void){
	int x,i,j,cont1=0,l;
	parola b[M];
	bool flag=false;	
	printf("INSERISCI UN NUMERO TRA 1 E 5:");
	scanf("%d",&x);
	printf("INSERISCI 10 PAROLE:\n");
	for(i=0;i<M;i++){
	    scanf("%s",b[i].a);
        converte(b[i].a);
	}
	printf("\n");
	
	if(x==1){		
		for(i=0;i<M;i++){
			l=strlen(b[i].a);
			   if(f1(b[i].a,l)){
				  cont1++;
			    }	
			    else{
			    	b[i].a[0]='\0';
				}
			}	
		for(j=0;j<M;j++){
			    if(b[j].a[0]!='\0'){
					printf("%s ",b[j].a);
					if(cont1>=3){
					   flag=true;
					}
			}
		}											 		
	} 
	

    if(x==2){
        for(i=0;i<M;i++){	
            l=strlen(b[i].a);
			   if(f2(b[i].a,l)){
				  cont1++;
			    }	
			    else{
			    	b[i].a[0]='\0';
				}
			}	
		for(j=0;j<M;j++){   
		    if(b[j].a[0]!='\0'){
   			    printf("%s ",b[j].a);
				if(cont1>=3){
				   flag=true;
				}					
			} 		
		}					    	
	}

     if(x==3){		
	    for(i=0;i<M;i++){
		    l=strlen(b[i].a);	
			   if(f3(b[i].a,l)){
				  cont1++;
			    }	
			    else{
			    	b[i].a[0]='\0';
				}
			}	
		for(j=0;j<M;j++){
			    if(b[j].a[0]!='\0'){
					printf("%s ",b[j].a);
					if(cont1>=3){
					   flag=true;
					} 
			    }
		}											 		
	} 
	
	
  if(x==4){	
		for(i=0;i<M;i++){	
		    l=strlen(b[i].a);
			   if(f4(b[i].a,l)){
				  cont1++;
			    }	
			    else{
			    	b[i].a[0]='\0';
				}
			}	
		for(j=0;j<M;j++){
			if(b[j].a[0]!='\0'){
				printf("%s ",b[j].a);
				if(cont1>=3){
				   flag=true;
				}
	     	}
		}											 		
	} 	
	
	
	if(x==5){		
		for(i=0;i<M;i++){	
			   if(f5(b[i].a,N)){
				  cont1++;
			    }	
			    else{
			    	b[i].a[0]='\0';
				}
		}	
		for(j=0;j<M;j++){
		    if(b[j].a[0]!='\0'){
				printf("%s ",b[j].a);
				if(cont1>=3){
				   flag=true;
				}
		    }
		}											 		
	} 
	
	
	
	if(flag){
		printf("VINTO");
	} 
	else{
		printf("PERSO");
	}	
	return 0;
}

void converte(char a[]){
    int i;
    for (i=0; i<strlen(a); i++){
        if(a[i]<='Z' && a[i]>='A') {
            a[i]=a[i]+32;
        }
    }
}


bool f1(char a[],int dim){
	int i,j,cont=0;
	bool flag=false;
	char v[6]="aeiou";
	for(i=0;i<dim;i++){
		for(j=0;j<5;j++){
		    if(a[i]==v[j])
		    cont++;		    
		}
	}
	if(cont>=3){
           flag=true;            		
	    }
	return flag;
}

bool f2(char a[],int dim){
	int i,cont=0;
	bool flag=false;
	for(i=0;i<dim-1;i++){		
		if(a[i]==a[i+1]){
			cont++;
			i++;
		}				
	}
	if(cont>=2){
		flag=true;
	}
	return flag;
}

bool f3(char a[],int dim){
	int i;
	bool flag=false;
	for (i=0;i<dim;i++){	
	    if(a[i]=='m'){
			flag=true;	
			} 
		if(flag){
			if(a[i]=='r')
			    flag=false;
		}									
	}
	return !flag;
}

bool f4(char a[],int dim){
	int i,j;
	bool flag=true,flagv1,flagv2;//flagv1 e flagv2 true se sono consonanti
	char v[6]="aeiou";
	for(i=0;i<dim-1;i++){
		flagv1=true;
		flagv2=true;
		for(j=0;j<5;j++){
		    if(a[i]==v[j]){
        	   flagv1=false; //flagv1=alse se a[i] sia vocale 
		    }	
		    if(a[i+1]==v[j]){
		    	flagv2=false;//flagv2=false se a[i+1] sia vocale
			}			
		}
		if(flagv1==flagv2){
				flag=false;
			}            
	}
	return flag;
}

	
bool f5(char a[],int dim){
	int i,l;
	l=strlen(a);
	char p[l+1];
	
	bool flag=true;
	for(i=0;i<l;i++){
		
		p[i]=a[l-i-1];
	
	}
	
	
	for(i=0;i<l;i++){
		if(p[i]!=a[i]){
			flag=false;
		}
	}
	return flag;			
}		
	
	
	
	
	
	
	
	
