#include<stdio.h>
#include<string.h>
#define R 5
#define C 6
#define DIM 100

int main()
{
    char puzzle[R][C],parola[C];
    int i,j,k,h,l,m,flag;
	
    do{
    	scanf("%s",puzzle[0]);
	}while(strlen(puzzle[0])!=30);
	
     for(i=0;i<R;i++)
    {
    	for(j=0;j<C;j++)
    	{
    		if(puzzle[i][j]<'a'||puzzle[i][j]>'z')
    		{
    			printf("Il carattere %c non e' valido.\nInserirne un altro: ",puzzle[i][j]);
    			do{
    				scanf("%c", &puzzle[i][j]);
				}while(puzzle[i][j]<'a'||puzzle[i][j]>'z');
			}
		}
	}
	
   	
   	for(m=0;strcmp(parola,"FINE")!=0;m++)
	{
	
		scanf("%s",parola);
		
		if(strcmp(parola,"FINE")!=0)
		{
			flag=7;
	
			for(i=0;i<R&&flag==7;i++)
			{
				for(j=0;j<C&&flag==7;j++)
				{
					k=j;
					flag=0;
					for(h=0;parola[h]!='\0'&&flag!=7&&k<C;h++)
					{
						if(puzzle[i][k]==parola[h])
						{
							flag++;
						}
						else flag=7;
						k++;	
					}
					if(flag!=strlen(parola))
					{
						flag=7;
					}
				}	
			}
	
			if(flag==7)	
			{
				for(i=0;i<C&&flag==7;i++)
				{
					for(j=0;j<R&&flag==7;j++)
					{
						k=j;
						flag=0;
						for(h=0;parola[h]!='\0'&&flag!=7&&k<R;h++)
						{
							if(puzzle[k][i]==parola[h])
							{
								flag++;
							}
							else flag=7;
							k++;	
						}
						if(flag!=strlen(parola))
						{
							flag=7;
						}
					}	
				}	
			}
	
			if(flag==7)
			{
				for(i=0;i<R&&flag==7;i++)
				{
					for(j=0;j<C&&flag==7;j++)
					{
						l=i;
						k=j;
						flag=0;
						for(h=0;parola[h]!='\0'&&flag!=7&&k<C&&l<R;h++)
						{
							if(puzzle[l][k]==parola[h])
							{
								flag++;
							}
							else flag=7;
							k++;	
							l++;
						}
						if(flag!=strlen(parola))
						{
							flag=7;
						}
					}	
				}
			}
	
			if(flag==strlen(parola))
			{
				printf("PRESENTE ");
			}	
			else
			{
				printf("ASSENTE ");
			}
		
		}
	}
	
	return 0;
}
