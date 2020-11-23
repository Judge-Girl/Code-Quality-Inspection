#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000000
int comp(const void *x, const void *y)
{
	return (*(long long *)x) - (*(long long *)y) > 0 ? 1 : -1;
}
static long long dates[MAX_N];
int main(void)
{
	int n;
	long long year, month, day;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld%lld", &year, &month, &day);
		dates[i] = day + month * 100 + year * 10000;
	}
	qsort(dates, n, sizeof(dates[0]), comp);
	for (int i = 0; i < n; i++)
	{
		printf("%lld %lld %lld\n", dates[i] / 10000, (dates[i] % 10000 - dates[i] % 100) / 100,
			   dates[i] % 100);
	}
	return 0;
}
