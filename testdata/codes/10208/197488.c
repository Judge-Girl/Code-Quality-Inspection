#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, h, c, d;
    scanf("%d %d %d %d %d", &a, &b, &h, &c, &d);

    int vol = a * b * h;

    int area = a * b - c * d;

    int newh = vol / area;

    printf("%d\n", newh);

    return 0;
}

