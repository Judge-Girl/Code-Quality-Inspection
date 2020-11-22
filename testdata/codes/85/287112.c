#include <stdio.h>
#include <stdlib.h>

typedef struct date
{
    int year, month, day;
}Date;

Date d[1000000];

int cmp(const void *ap, const void *bp)
{
    Date *a = (Date *)ap;
    Date *b = (Date *)bp;
    if(a->year != b->year)
        return a->year - b->year;
    if(a->month != b->month)
        return a->month - b->month;
    return a->day - b->day;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d", &d[i].year, &d[i].month, &d[i].day);
    qsort(d, n, sizeof(Date), cmp);
    for(int i=0; i<n; i++)
        printf("%d %d %d\n", d[i].year, d[i].month, d[i].day);
    return 0;
}
