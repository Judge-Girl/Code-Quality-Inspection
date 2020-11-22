#include<stdio.h>
#define MAXN 1<<28
int count[MAXN] = {0};
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
int lon(int y, int m, int d)
{
	return ((y << 9) | (m << 5)) | d;
}
void printd(int n)
{
	int y, m, d;
	d = n & 31;
	n >>= 5;
	m = n & 15;
	n >>= 4;
	y = n;
	printf("%d %d %d\n", y, m, d);
	return;
}
int main()
{
	int N, i, y, m, d, maxk = 0, mink = MAXN, j;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		//scanf("%d %d %d", &y, &m, &d);
		ReadInt(&y);
		ReadInt(&m);
		ReadInt(&d);
		int k = lon(y, m, d);
		count[k]++;
		if(k > maxk)	maxk = k;
		if(k < mink)	mink = k;
		//printf("%d\n", k);
	}
	for(i = mink, j = 0; i <= maxk && j < N; i++)
	{
		if(count[i])
		{
			printd(i);
			j++;
		}
		else	continue;
		if(j == N-1){
			printd(maxk);
			break;
		}
	}		
	return 0;
}

