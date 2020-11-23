#include <stdio.h>
#include <stdlib.h>
 
typedef struct date
{
    int y, m, d;
}date;
 
struct date re[1000010];
 
int comp(const void *a, const void *b)
{
    struct date a2 = *(date *)a;
    struct date b2 = *(date *)b;
    if(a2.y == b2.y)
    {
        if(a2.m == b2.m) return a2.d - b2.d;
        else return a2.m - b2.m;
    }
    else return a2.y - b2.y;
}
 
int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d%d%d", &re[i].y, &re[i].m, &re[i].d);
    qsort(re, n, sizeof(re[0]), comp);
    for(i = 0; i < n; i++)
        printf("%d %d %d\n", re[i].y, re[i].m, re[i].d);
    return 0;
}
