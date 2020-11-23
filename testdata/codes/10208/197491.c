#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,h,c,d;
    scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
    int xd=(a*b)-(c*d);
    int xh=(a*b)*h;
    int ans=xh/xd;
    printf("%d",ans);
}

