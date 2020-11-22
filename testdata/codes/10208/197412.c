#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,h,c,d;
    int i;
    scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
    i=(a*b*h)/(a*b-c*d);
    printf("%d",i);
    return 0;
}

