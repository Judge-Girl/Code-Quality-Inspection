#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

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


typedef struct{
    int y, m, d;
} Date;

int compare(const void *a, const void *b){
    Date *ptr1 = (Date *)a;
    Date *ptr2 = (Date *)b;

    if(ptr1->y < ptr2->y) return -1;
    else if(ptr1->y > ptr2->y) return 1;
    else if(ptr1->m < ptr2->m) return -1;
    else if(ptr1->m > ptr2->m) return 1;
    else if(ptr1->d < ptr2->d) return -1;
    else if(ptr1->d > ptr2->d) return 1;
    else return 0;
}

int main(){
    int num;
    scanf("%d", &num);
    Date *date = malloc(num * sizeof(Date));
    for(int i = 0; i < num; i++){
        ReadInt(&date[i].y);
        ReadInt(&date[i].m);
        ReadInt(&date[i].d);
    }
    qsort(date, num, sizeof(Date), compare);
    for(int i = 0; i < num; i++){
        printf("%d %d %d\n", date[i].y, date[i].m, date[i].d);
    }
    free(date);
}
