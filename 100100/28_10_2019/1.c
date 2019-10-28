#include <stdio.h>
int main()
{
    int a,b;
    b=0;
    printf("ins num \t");
    scanf("%d",&a);
    do
    {
        b=b*10+a%10;
        a=a/10;
    }while(a/10!=0);
    b=b*10+a;
    printf("%d",b);
    return 0;
}
