#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, h; // tank
    int c ,d;

    scanf("%d%d%d", &a, &b, &h);
    scanf("%d%d", &c, &d);

    int volume = a*b*h;

    int ogArea = a*b;

    int brickArea = c*d;

    int newArea = ogArea - brickArea;

    int depth = volume / newArea;

    printf("%d", depth);

    return 0;

}
