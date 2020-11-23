#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000000

typedef struct date {
    int year, month, day;
} Date;

Date date[MAXN];

int compare(const void *a, const void *b) {
    Date dateA = *(Date *)a;
    Date dateB = *(Date *)b;
    if(dateA.year != dateB.year)
        return dateA.year - dateB.year;
    if(dateA.month != dateB.month)
        return dateA.month - dateB.month;
    return dateA.day - dateB.day;
}

int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) 
        scanf("%d %d %d", &date[i].year, &date[i].month, &date[i].day);

    qsort(date, N, sizeof(Date), compare);

    for (int i = 0; i < N; i++)
        printf("%d %d %d\n", date[i].year, date[i].month, date[i].day);
    
    return 0;
}
