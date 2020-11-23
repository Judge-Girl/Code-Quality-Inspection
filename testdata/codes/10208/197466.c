#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, h, c, d;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    int h_after;
    h_after = a * b * h / (a * b - c * d);
    printf("%d\n", h_after);
    //a * b * h_after == a * b * h + c * d * h_after
    return 0;
}

