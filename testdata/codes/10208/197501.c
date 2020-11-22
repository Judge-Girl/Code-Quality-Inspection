#include <stdio.h>

int main(void)
{
    int a, b, h, c, d;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    int volume = a * b * h;
    int depth = volume / (a * b - c * d);
    printf("%d\n", depth);
    return 0;
}

