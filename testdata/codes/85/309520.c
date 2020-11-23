#include <stdio.h>
#include <stdlib.h>
 
typedef struct date{
    int year;
    int month;
    int day;
}   Date;
 
int compare(const void *a, const void *b);
Date dates[1<<20];
int main(void){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &dates[i].year, &dates[i].month, &dates[i].day);
    qsort(dates, n, sizeof(Date), &compare);
    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", dates[i].year, dates[i].month, dates[i].day);
    return 0;
 
}
 
int compare(const void *a, const void *b){
    Date *A = (Date *)a;
    Date *B = (Date *)b;
    return (A->year - B->year) * 10000 + (A->month - B->month) * 100 + (A->day - B->day);
}
