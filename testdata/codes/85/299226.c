#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct {
    int year;
    int month;
    int day;
} date;
int cp(const void*a,const void *b)
{
    date **p = (date **)a;
    date **q = (date **)b;
    date *x = *p,*y=*q;
    if(x->year<y->year)
        return -1;
    else if(x->year>y->year)
        return 1;
    else if(x->month<y->month)
        return -1;
    else if(x->month>y->month)
        return 1;
    else if(x->day<y->day)
        return -1;
    else if(x->day>y->day)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    date **d = (date **)malloc(sizeof(date*) * n);
    date *x = (date *)malloc(sizeof(date)*n);
    for (int i = 0; i < n;i++)
    {
        d[i] = x+i;
        scanf("%d%d%d", &d[i]->year, &d[i]->month, &d[i]->day);
    }    
    qsort(d, n, sizeof(date*), cp);
    for (int i = 0; i < n;i++)
        printf("%d %d %d\n", d[i]->year, d[i]->month, d[i]->day);
}
