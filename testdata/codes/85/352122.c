#include <stdio.h>
#include <stdlib.h>
 
#include <stdio.h>
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

void printNum(int num){
    char buf[16];
    unsigned char count = 0;
    while (num != 0){
        buf[count++] = num % 10 + '0';
        num /= 10;
    }
    while (count != 0)
        putchar(buf[--count]);
}

int compare(const void *a, const void *b);
int dates[1<<20];
int main(void){
    int n;
    scanf("%d", &n);
    int year, month, day;
    for (int i = 0; i < n; i++){
        ReadInt(&year);
        ReadInt(&month);
        ReadInt(&day);
        dates[i] = (year << 9) + (month << 5) + day;
    }
    qsort(dates, n, sizeof(int), &compare);
    for (int i = 0; i < n; i++){
        printNum(dates[i] >> 9);
        putchar(' ');
        dates[i] &= 0x01ff;
        printNum(dates[i] >> 5);
        putchar(' ');
        dates[i] &= 0x001f;
        printNum(dates[i]);
        putchar('\n');
    }
    return 0;
 
}
 
int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
