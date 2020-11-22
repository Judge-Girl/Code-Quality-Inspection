#include <stdio.h>
#include <stdlib.h>
 
typedef struct{
    int year;
    int month;
    int day;
}Date;
 
int cmp(const void *A, const void *B)
{
    Date *a = (Date *)A;
    Date *b = (Date *)B;
    if(a->year > b->year)
        return 1;
    else if(a->year < b->year)
        return -1;
    if(a->month > b->month)
        return 1;
    else if(a->month < b->month)
        return -1;
    if(a->day > b->day)
        return 1;
    else if(a->day < b->day)
        return -1;
    return 0;
}
Date date[1000000];
int main()
{
    int n;
    scanf("%d", &n);
 
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &date[i].year, &date[i].month, &date[i].day);
    }
    qsort(date, n, sizeof(Date), cmp);
    for(int i=0; i<n; i+=5){
        printf("%d %d %d\n%d %d %d\n%d %d %d\n%d %d %d\n%d %d %d\n", date[i].year, date[i].month, date[i].day, date[i+1].year, date[i+1].month, date[i+1].day, date[i+2].year, date[i+2].month, date[i+2].day, date[i+3].year, date[i+3].month, date[i+3].day, date[i+4].year, date[i+4].month, date[i+4].day);
    }
}
