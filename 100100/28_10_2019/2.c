/**
 * @author 100100
 *
 */

#include <stdio.h>
#include <string.h>

#define N 50

int main()
{
    char str1[N];
    char str2[N];
    int i,j,k,lung1,lung2,cont;
    cont=0;
    printf("ins 1 str \n");
    scanf("%s",str1);
    printf("ins 2 str \n");
    scanf("%s",str2);
    lung1=strlen(str1);
    lung2=strlen(str2);
    for(i=0;i<lung1;i++)
    {
        k=0;
        j=0;
        if(str1[i]==str2[0])
        {
			for(j=0;j<lung2;j++)
			{
				if(str1[i+j]==str2[j])
				{
					k++;
				}
				if(k==lung2)
				{
					cont++;
				}
			}
        }
    }
    printf("volte %d \n",cont);
    return 0;
}