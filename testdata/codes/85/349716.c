#include <stdio.h>
#include <stdlib.h>
#define maxday 1000000

typedef struct day
{
	int year;
	int month;
	int date;
}day;

day allday[maxday];

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

int cmp(const void *data1, const void *data2)
{
	day *ptr1 = (day*)data1;
	day *ptr2 = (day*)data2;
	if(ptr1 -> year < ptr2 -> year)
		return -1;
	else if(ptr1 -> year > ptr2 -> year)
		return 1;
	else if(ptr1 -> month < ptr2 -> month)
		return -1;
	else if(ptr1 -> month > ptr2 -> month)
		return 1;
	else if(ptr1 -> date < ptr2 -> date)
		return -1;
	else if(ptr1 -> date > ptr2 -> date)
		return 1;
	else 
		return 0;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		ReadInt(&allday[i].year);
		ReadInt(&allday[i].month);
		ReadInt(&allday[i].date);
	}
	qsort(allday,n,sizeof(day),cmp);
	for(int i=0;i<n;i++)
		printf("%d %d %d\n",allday[i].year,allday[i].month,allday[i].date);

}
