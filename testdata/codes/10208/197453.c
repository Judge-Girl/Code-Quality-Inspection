#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, h, c, d;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);

    int volume_water;
    volume_water = a * b * h;

    int new_height = a*b - c*d;

    printf("%d\n", volume_water / new_height);


    return 0;
}

