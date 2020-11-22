#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, h, c, d;
    int x;
    scanf("%d\n", &a);
    scanf("%d\n", &b);
    scanf("%d\n", &h);
    scanf("%d\n", &c);
    scanf("%d\n", &d);

    x= (a*b*h)/((a*b)-(c*d));

    printf("%d\n", x);

    return 0;
}

