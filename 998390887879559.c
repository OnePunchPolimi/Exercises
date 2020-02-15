#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{  /*il puntatore next è per gestire meglio la creazione della mappa*/
    char dato;
    struct node* nord;
    struct node* est;
    struct node* sud;
    struct node* ovest;
    struct node* next;
    int cont;      /*per sapere l'indice*/
    int flag;    /*per sapere se è passato su quella casella*/
    
}Nodo;

typedef Nodo* Ptrnodo;
void trova_righecolonne(FILE* fp,int *r,int *c);
void leggi_mappa(FILE *fp,char* stringa);
void StampaMappa(Ptrnodo testa,int colonne);
void LeggiPercorso(FILE* fp,char* percorso);
void LunghezzaFile(FILE* fp,int* len);
void VerificaPercorsi(Ptrnodo testa,char * percorso);
void Destroy(Ptrnodo testa);
Ptrnodo inizializza_mappa(Ptrnodo testa,int righe,int colonne,char * lettera);
Ptrnodo Inserisci(Ptrnodo lista,int i, int j, char lettera,int righe,int colonne,int k);
Ptrnodo Salta(Ptrnodo lista,int num);
Ptrnodo RamificaSud(Ptrnodo testa,int colonne,int righe);
Ptrnodo RamificaNord(Ptrnodo testa,int colonne,int righe);
Ptrnodo RamificaEst(Ptrnodo testa,int colonne,int righe);
Ptrnodo RamificaOvest(Ptrnodo testa,int colonne,int righe);
Ptrnodo Percorri(Ptrnodo temp,int* flag1,char lettera);
Ptrnodo Azzera(Ptrnodo testa);
int Verifica(Ptrnodo testa);

int main(int argc, const char * argv[]) {
    /*ATTENZIONE: NEL CASO L'APERTURA DEL FILE NON VADA A BUON FINE, PASSARE IL PERCORSO COMPLETO E NON SOLO IL NOME*/
    
    int righe, colonne;
    FILE* fp;
    char * stringa;
    char * percorso;
    Ptrnodo testa;
    testa = NULL;
    int lunghezza;
    int* plunghezza;
    plunghezza=&lunghezza;
    lunghezza=0;
    if(argc<2){   /*verifico se il nome del file è stato passato*/
        printf("Nome file non ricevuto\n");
        return -1;
    }
    
    
    fp=fopen(argv[1],"r");
    if(fp){
        trova_righecolonne(fp, &righe, &colonne); /*per sapere il numero di righe e colonne*/
        stringa=(char*)malloc(righe*colonne*sizeof(char));
        leggi_mappa(fp,stringa); /*copio la mappa in una stringa*/
        rewind(fp);    /*per sicurezza riavvio il file*/
        LunghezzaFile(fp,plunghezza);   /*in modo da sapere la dimensione per la malloc*/
        rewind(fp);
        percorso=(char*)malloc(lunghezza*sizeof(char));
        /*if(stringa&&percorso){*/ /*(Se si vuole fare un controllo sulle stringhe dinamiche)*/
        LeggiPercorso(fp,percorso);   /*metto i percorsi degli elfi in una stringa*/
        testa=inizializza_mappa(testa,righe,colonne,stringa); /*creo la mappa con la lista*/
        /*StampaMappa(testa,colonne);*/ /*questa funzione nel caso stampa la mappa letta*/
        testa=RamificaSud(testa,colonne,righe);   /*aggiungo i puntatori alle quattro possibili direzioni*/
        testa=RamificaEst(testa,colonne,righe);
        testa=RamificaNord(testa,colonne,righe);
        testa=RamificaOvest(testa,colonne,righe);
        testa=Azzera(testa);   /*azzero nel senso che non è ancora passato su nessuna casella*/
        VerificaPercorsi(testa,percorso);   /*verifico e stampo la risposta*/
        Destroy(testa);  /*Libero la memoria*/
        printf("\n");
        fclose(fp);
            
      /*  }
        else printf("Errore allocazione memoria");*/
    }
    else {
        printf("Errore apertura file\n");
        return -1;
    }
   
    return 0;
}


void trova_righecolonne(FILE* fp,int *r,int *c){

char ch;
*c = 0;
*r = 0;

fscanf(fp,"%c",&ch);
while(ch != '\n')
{
    (*c)++;
    fscanf(fp,"%c",&ch);
}
(*r)++;
while(ch != 'S'){
    fscanf(fp,"%c",&ch);
    if(ch == '\n')
        (*r)++;
}
rewind(fp);
return;
}

Ptrnodo  inizializza_mappa(Ptrnodo testa,int righe,int colonne,char * lettera){
    int i,j;
    int k=1;
    int ch;
  
    for (i=1; i<=righe; i++) {
        for (j=1; j<=colonne; j++,lettera++,k++) {
            ch=(*lettera);
            testa=Inserisci(testa,i,j,ch,righe,colonne,k);
    
        }
        
       
    }
    
    return testa;
}


void leggi_mappa(FILE *fp,char* stringa){    /*mette la mappa in una stringa*/
    char ch;
    fscanf(fp,"%c",&ch);
    while(ch!='S'){
        if(ch!='\n'){
            (*stringa)=ch;
            stringa++;
        }
        fscanf(fp,"%c",&ch);
        
    }
    (*stringa)='\0';
    
    
    return;
}

void StampaMappa(Ptrnodo testa,int colonne){
    Ptrnodo temp;
    temp=testa;
    if(temp!=NULL){
        printf("%c ",temp->dato);
    while(temp->next!=NULL){
        temp=temp->next;
         printf("%c ",temp->dato);
        if((temp->cont%colonne)==0)
            printf("\n");
        
    }
        
    }
    else printf("VUOTA\n");

}

Ptrnodo Inserisci(Ptrnodo testa,int i, int j, char lettera,int righe,int colonne,int k){
    Ptrnodo temp;    /*per creare il nodo*/
    Ptrnodo appoggio;  /*per scorrere la lista*/
    appoggio=testa;
    char ch;
    ch=lettera;
    temp=(Ptrnodo)malloc(sizeof(Nodo));
        if(temp){
            
            temp->dato=ch;
            temp->cont=k;
            temp->next=NULL;
            if(i==1){
                           temp->nord=NULL;  /*se nella prima riga*/
                    }
            if(j==1){
                           temp->ovest=NULL; /*se nella prima colonne*/
                    }
            if(i==righe){
                           temp->sud=NULL;
                        }
            if(j==colonne){
                           temp->est=NULL;
                          }
            
            if(testa==NULL){
                testa=temp;
                return testa;
               
            }
        
                while(appoggio->next!=NULL){
                appoggio=appoggio->next;
            
            }
            appoggio->next=temp;
            return testa;
        }
        else {printf("Errore allocazione memoria\n");
        }
            return testa;
    
}

Ptrnodo Salta(Ptrnodo lista,int num){ /*per scorrere di num nodi*/
    if(num==0)
        return lista;
    else return Salta(lista->next,num-1);
    

}

void LeggiPercorso(FILE* fp,char * percorso){
    char ch;
    fscanf(fp,"%c",&ch);
    while(ch!='P'){
        fscanf(fp,"%c",&ch);
    }
    fscanf(fp,"%c",&ch);
    while(!feof(fp)){
        
            (*percorso)=ch;
            percorso++;
        
        fscanf(fp,"%c",&ch);
        
    }
    (*percorso)='\0';
    
    return;
    
}

void LunghezzaFile(FILE * fp,int * len){
    int k;
    char ch;
    k=0;
    rewind(fp);
   fscanf(fp,"%c",&ch);
   do{
        (*len)++;
       fscanf(fp,"%c",&ch);
   
    }while(!feof(fp));
    (*len)--;

    return;
}

Ptrnodo RamificaSud(Ptrnodo testa,int colonne,int righe){
    Ptrnodo temp;
    temp=testa;
    while(temp->next!=NULL){
        if(temp->sud!=NULL||temp->cont<(righe-1)*colonne){
            temp->sud=Salta(temp,colonne);
        }
        
        temp=temp->next;
    }
    
    return testa;
}

Ptrnodo RamificaEst(Ptrnodo testa,int colonne,int righe){
    Ptrnodo temp;
    temp=testa;
    while(temp->next!=NULL){
        if(temp->est!=NULL||((temp->cont)%colonne!=0)){
           temp->est=temp->next;
        }
        
        temp=temp->next;
    }

    return testa;
}

Ptrnodo RamificaNord(Ptrnodo testa,int colonne,int righe){
    Ptrnodo temp1,temp2;
    temp1=testa;
    while(temp1->next!=NULL){
        if(temp1->nord!=NULL||temp1->cont>colonne){
            temp2=testa;
            while(temp2->cont<temp1->cont){
                if(temp2->cont==(temp1->cont-colonne)){
                    temp1->nord=temp2;
                }
                temp2=temp2->next;
            }
            
        }
        
        
        temp1=temp1->next;
    }


return testa;
}

Ptrnodo RamificaOvest(Ptrnodo testa,int colonne,int righe){
    Ptrnodo temp1;
    temp1=testa;
    while(temp1->next!=NULL){
        if(temp1->ovest!=NULL||(temp1->cont)%colonne!=1){
       
            temp1->ovest=Salta(testa, (temp1->cont)-2);
        }
        
        temp1=temp1->next;
    }

    return testa;
}

void VerificaPercorsi(Ptrnodo testa,char * percorso){
    Ptrnodo temp,testa2;
    testa2=testa;
    int flag1=1;  /*per controllare se non va fuori dalla mappa*/
    int flag2=1; /*per controllare se non prende ostacoli e prende tutti i camini*/
    int len;
    int cont=0;
    len=strlen(percorso);
    while((*percorso)!='\0'&&cont<len){
        flag1=1;
        flag2=1;
        
        while((*percorso)!=' '){
            printf("%c",(*percorso));
            percorso++;
            cont ++;
        }  printf(" ");
           percorso++;
        cont++;
        temp=testa;
        temp->flag=1;
        while((*percorso)!='\n'){
            
            temp=Percorri(temp,&flag1,(*percorso));
            temp->flag=1;
            percorso++;
            cont++;
            }
        flag2=Verifica(testa);
		
		printf("flag1: %d flag2 %d ",flag1,flag2);
        if(flag1==1&&flag2==1){
            printf("SI\n");
        }
      
        if(flag1==0||flag2==0)
            printf("NO\n");
   
        testa=Azzera(testa);  /*per il percorso successivo*/
        percorso++;
        cont++;
        
    }
    
}

Ptrnodo Azzera(Ptrnodo testa){
    Ptrnodo temp;
    temp=testa;
    while(temp->next!=NULL){
        temp->flag=0;
        temp=temp->next;
    }
    
    return testa;
}

Ptrnodo Percorri(Ptrnodo temp,int * flag1,char lettera){
    
    if(lettera=='N'&&temp->nord!=NULL){
        temp=temp->nord;
        return temp;
        
    }
    if(lettera=='N'&&temp->nord==NULL){
        (*flag1)=0;
        return temp;
        
    }
    if(lettera=='E'&&temp->est!=NULL){
        temp=temp->est;
        return temp;
        
    }
    if(lettera=='E'&&temp->est==NULL){
        (*flag1)=0;
        return temp;
        
    }
    if(lettera=='S'&&temp->sud!=NULL){
        temp=temp->sud;
        return temp;
        
    }
    
    if(lettera=='S'&&temp->sud==NULL){
        (*flag1)=0;
        return temp;
        
    }
    if(lettera=='O'&&temp->ovest!=NULL){
        temp=temp->ovest;
    return temp;
        
    }
    if(lettera=='O'&&temp->ovest==NULL){
        (*flag1)=0;
        return temp;
        
    }
    
    return temp;
}

int Verifica(Ptrnodo testa){
    Ptrnodo temp;
    temp=testa;
    while(temp->next!=NULL){
        if(temp->flag==1&&temp->dato=='O'&&temp->cont!=1){
            
            return 0;
        }
        if (temp->flag==0&&temp->dato=='X'&&temp->cont!=1) {
    
            return 0;
        }
        temp=temp->next;
    }
    return 1;
}

void Destroy(Ptrnodo testa){
    if(testa!=NULL){
        Destroy(testa->next);
        free(testa);
    }
}
