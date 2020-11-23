#include <stdio.h>

int first_x[50000], first_y[50000], second_x[50000], second_y[50000];
int Adistance(int x, int y, int r);
int Bdistance(int x, int y, int r);
int main(void)
{
    int i, r;
    scanf("%d", &r);
    int x, y;
    scanf("%d %d", &x, &y);
    first_x[0] = x;
    first_y[0] = y;
    scanf("%d %d", &x, &y);
    second_x[0] = x;
    second_y[0] = y;
    printf("%d\n", Adistance(x, y, 1));
    for (i = 1; i < r; i++) {
        scanf("%d %d", &x, &y);
        first_x[i] = x;
        first_y[i] = y;
        printf("%d\n", Bdistance(x, y, i));
        scanf("%d %d", &x, &y);
        second_x[i] = x;
        second_y[i] = y;
        printf("%d\n", Adistance(x, y, i + 1));
    }
    return 0;
}

int Adistance(int x, int y, int r)
{
    int i, j, min = 100000;
    for (i = 0; i < r; i++)
        if (abs(first_x[i] - x) + abs(first_y[i] - y) < min)
            min = abs(first_x[i] - x) + abs(first_y[i] - y);
    return min;
}
int Bdistance(int x, int y, int r)
{
    int i, j, min = 100000;
    for (i = 0; i < r; i++)
        if (abs(second_x[i] - x) + abs(second_y[i] - y) < min)
            min = abs(second_x[i] - x) + abs(second_y[i] - y);
    return min;
}

