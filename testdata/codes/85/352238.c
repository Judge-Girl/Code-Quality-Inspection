#include <stdio.h>
#include <stdlib.h>
#define maxN 1000000
typedef struct date{
    int year;
    int month;
    int day;
}Date;

int hasEOF = 0;

int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

int compare(const void *A, const void *B){
    Date *a = (Date *)A;
    Date *b = (Date *)B;
    if(a->year != b->year)
        return a->year - b->year;
    if(a->month != b->month)
        return a->month - b->month;
    if(a->day != b->day)
        return a->day - b->day;
    return 0;
}
Date dates[maxN];
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        ReadInt(&dates[i].year);
        ReadInt(&dates[i].month);
        ReadInt(&dates[i].day);
    }
    qsort(dates, n, sizeof(Date), compare);
    
    for(int i = 0; i < n; i++)
        printf("%d %d %d\n", dates[i].year, dates[i].month, dates[i].day);
}
