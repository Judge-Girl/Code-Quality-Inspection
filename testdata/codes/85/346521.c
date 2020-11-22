#include<stdio.h>
#define MAXN 1<<28
int count[MAXN] = {0};
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
		scanf("%d %d %d", &y, &m, &d);
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

