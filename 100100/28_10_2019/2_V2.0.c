#include <stdio.h>
#include <string.h>
#define N 50
int main()
{
    char str1[N+1];
    char str2[N+1];
    int i,j,k,lung1,lung2,cont;
    int temp;
    cont=0;
    printf("ins 1 str \n");
    gets(str1);
    printf("ins 2 str \n");
    gets(str2);
    lung1=strlen(str1);
    lung2=strlen(str2);
    for(i=0;i<lung1;i++)
    {
        k=0;
        j=0;
        if(str1[i]==str2[0])
        {
            temp=i;
        for(j=0;j<lung2 && str2[j]!='\n' && str2[j]!='\0';j++)
        {
            if(str1[i]==str2[j])
            {
                k++;
                i++;
            }
            if(k==lung2)
            {
                cont++;
            }
        }
        i=temp+1;
        }
    }
    printf("volte %d \n",cont);
    return 0;
}