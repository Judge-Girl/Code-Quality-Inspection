#include <stdio.h>
#include <stdlib.h>
#define MAXN 50000

typedef struct {
    int n;
    int x[MAXN];
    int y[MAXN];
}Data;
 
int calDis(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2) + abs(y1-y2);
}

int findMax(Data *data, int x, int y)
{
    int min = 1<<20;
    for(int i=0; i<data->n; i++){
        int dis = calDis(x, y, data->x[i], data->y[i]);
        if(dis < min)
            min = dis;
    }
    return min;
}

int main()
{
    int n;
    scanf("%d", &n);

    Data a, b;
    a.n = 0;
    b.n = 0;
    for(int i=0; i<n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        a.x[a.n] = x;
        a.y[a.n++] = y;
        if(i != 0)
            printf("%d\n", findMax(&b, x, y));

        scanf("%d%d", &x, &y);
        b.x[b.n] = x;
        b.y[b.n++] = y;
        printf("%d\n", findMax(&a, x, y));
    }  
}
