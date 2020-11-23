#include <stdio.h>
#include<stdlib.h>
int n;
struct date{
    int year;
    int month;
    int day;
};
typedef struct date Date;
int cmp(Date *a , Date *b){
    if((a->year) > (b->year))return 1;
    if((a->year) < (b->year))return -1;
    if((a->year) == (b->year)){
        if((a->month) > (b->month))return 1;
        if((a->month) < (b->month))return -1;
        if((a->month) == (b->month)){
            if((a->day) > (b->day))return 1;
            if((a->day) < (b->day))return -1;
            if((a->day) == (b->day))return 0;
        }
    }
}
Date a[1000000];
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
int main() {
    scanf("%d" , &n);
    int year , month , day;
    int count = 0;
    while (ReadInt(&year)) {
        ReadInt(&month);
        ReadInt(&day);
        a[count].year = year;
        a[count].month = month;
        a[count].day = day;
        count ++;
    }
    qsort(a , n , sizeof(Date) , cmp);
    for(int i = 0 ; i < n ; i++){
        printf("%d %d %d\n" , a[i].year , a[i].month , a[i].day);
    }
    return 0;
}

