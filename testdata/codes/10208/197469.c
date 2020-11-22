#include<stdio.h>
int main()
{
    int a,b,h,c,d;
    scanf("%d%d%d%d%d", &a,&b,&h,&c,&d);
    int k;
    k = a*b*h/(a*b-c*d);
    printf("%d", k);
    return 0;
}

