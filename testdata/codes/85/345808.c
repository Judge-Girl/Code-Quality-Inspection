#include<stdio.h>
#include<stdlib.h>

int cmp(long long int *a, long long int *b)
{
	if (*a > *b)
		return 1;
    return 0;
}

long long int num[1000000] = {};
int main(void)
{
    int N;
    scanf("%d", &N);
	int year, month, day;
    for (int i = 0; i < N; i++){
        scanf("%d%d%d", &year, &month, &day);
		num[i] = day + month * 100 + (long long int)year * 10000;
	}
    qsort(num, N, sizeof(long long int), cmp);
    for (int i = 0; i < N; i++)
        printf("%lld %lld %lld\n", num[i]/10000, (num[i]/100)%100, num[i]%100);
}

