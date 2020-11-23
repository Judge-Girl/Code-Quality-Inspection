#include <stdio.h>
#include <stdlib.h>

int hasEOF = 0;
int date[1000000];

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

int comp(const void * A,const void * B){
    return *(int *)A - *(int *)B;
}

void write(int x){
    if (!x) putchar('0');
    else{
        char s[100];
        int i,j=0;
        for (;x>0;x/=10) s[j++]=x%10;
        for (i=j-1;i>=0;i--) putchar(s[i]+48);
    }
}

int main() {
    int N;
    scanf("%d",&N);
    int i = 0,y,m,d;
    while (ReadInt(&y) && ReadInt(&m) && ReadInt(&d)) {
        date[i] |= (y << 9) | (m << 5) | d;
        i++;
    } 
    qsort(date,N,sizeof(int),comp);
    for(int i = 0;i < N;i++){
        write(date[i] >> 9);
        putchar(' ');
        write((date[i] >> 5) & 15);
        putchar(' ');
        write(date[i] & 31);
        putchar('\n');
    }
 
    return 0;
}
