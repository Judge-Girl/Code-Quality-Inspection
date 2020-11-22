#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,h,c,d,ov,nv;

    scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);

    ov=a*b*h;
    nv=ov/(a*b-c*d);

    printf("%d",nv);

    return 0;
}

