#include<stdio.h>

int main(void)
{
    int a, b, h, c, d;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    int x = a * b * h / (a * b - c * d);
    printf("%d", x);
}

