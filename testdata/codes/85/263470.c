#include <stdio.h>
#include <stdlib.h>

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

int cmp(const void *a, const void *b){
	Date *date1 = (Date *)a, *date2 = (Date *)b;
	if(date1 -> year < date2 -> year) return -1;
	if(date1 -> year > date2 -> year) return 1;
	if(date1 -> month < date2 -> month) return -1;
	if(date1 -> month > date2 -> month) return 1;
	if(date1 -> day < date2 -> day) return -1;
	if(date1 -> day > date2 -> day) return 1;
	return 0;
}

Date date[1000005];

int main(void)
{
	int n, y, m, d;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		ReadInt(&y);
		ReadInt(&m);
		ReadInt(&d);
		date[i].year = y;
		date[i].month = m;
		date[i].day = d;
	}
	qsort(date, n, sizeof(Date), cmp);
	for(int i = 0; i < n; i++) printf("%d %d %d\n", date[i].year, date[i].month, date[i].day);
	return 0;
}
