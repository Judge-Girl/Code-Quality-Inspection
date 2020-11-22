#include <stdio.h>

int main(void)
{
    int a, b, h, c, d;

    // area --> ab - cd
    // water volume = a*b*h
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);

    printf("%d", (a * b * h) / (a * b - c * d));
    
    return 0;
}
