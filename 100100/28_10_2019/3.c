#include <stdio.h>
#define N 10
int funzione(int);
int main()
{
    int maxg,maxl,temp;
    int num[N];
    int i,g;
    for(i=0;i<N;i++)
    {
        printf("ins ele num %d \n",i);
        scanf("%d",&num[i]);
    }
    maxg=0;
    for(i=0;i<N;i++)
    {
        temp=num[i];
        g=funzione(temp);
        if(g==1)
        {
            maxl=temp;
            if(maxl>maxg)
            {
                maxg=maxl;
            }
        }
    }
    printf("il massimo numero perfetto e' %d",maxg);
    return 0;
}
int funzione(int num)
{
    int i,j;
    int s=0;
    for(i=1;i<num;i++)
    {
        if(num%i==0)
        {
            s=s+i;
        }
    }
    if(s==num)
    {
        j=1;
        printf("il numero %d e' perfetto \n",num);
    }
    else
    {
        j=0;
    }
    return j;
}