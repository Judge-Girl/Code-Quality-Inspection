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
        printf("%d ", (dates[i] >> 9));
        dates[i] &= 0x01ff;
        printf("%d ", dates[i] >> 5);
        dates[i] &= 0x001f;
        printf("%d\n", dates[i]);
    }
    return 0;
 
}
 
int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
