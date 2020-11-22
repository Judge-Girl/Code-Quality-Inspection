#include <stdio.h>
main()
{
    int a,b,h,c,d,h2;
    scanf("%d\n%d\n%d\n%d\n%d\n",&a,&b,&h,&c,&d);
    h2=a*b*h/(a*b-c*d);
    printf("%d",h2);
    return 0;
}

