#include <stdio.h>
int main ()
{
    int a,b,h,c,d,x,z,q;
    scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
    x=a*b*h;
    z=(a*b)-(c*d);
    q=x/z;

    printf("%d\n",q);

    return 0;
}

