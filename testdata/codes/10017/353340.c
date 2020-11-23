#include <stdio.h>
#include <stdlib.h>

#define MAXN 50000

int main()
{
    int n, min;
    scanf("%d", &n);
    int a[MAXN][2];
    int b[MAXN][2];
    for (int i = 0; i < n; i++)
        scanf("%d%d%d%d", &a[i][0], &a[i][1], &b[i][0], &b[i][1]);
    printf("%d\n", abs(a[0][0] - b[0][0]) + abs(a[0][1] - b[0][1]));
    for (int i = 1; i < n; i++) {
        min = 1 << 18;
        for (int j = 0; j < i; j++)
            if (abs(a[i][0] - b[j][0]) + abs(a[i][1] - b[j][1]) < min)
                min = abs(a[i][0] - b[j][0]) + abs(a[i][1] - b[j][1]);
        printf("%d\n", min);
        min = 1 << 18;
        for (int j = 0; j <= i; j++)
            if (abs(b[i][0] - a[j][0]) + abs(b[i][1] - a[j][1]) < min)
                min = abs(b[i][0] - a[j][0]) + abs(b[i][1] - a[j][1]);
        printf("%d\n", min);
    }
}
