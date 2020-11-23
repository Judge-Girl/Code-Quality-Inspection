#include<stdio.h>
#include<stdlib.h>

int cmp(unsigned int *a, unsigned int *b)
{
	if (*a > *b)
		return 1;
    return 0;
}

unsigned int num[1000000] = {};
int main(void)
{
    int N;
    scanf("%d", &N);
	unsigned int year, month, day;
    for (int i = 0; i < N; i++){
        scanf("%u%u%u", &year, &month, &day);
		num[i] = day + month * 100 + (unsigned int)year * 10000;
	}
    qsort(num, N, sizeof(unsigned int), cmp);
    for (int i = 0; i < N; i++)
        printf("%u %u %u\n", num[i]/10000, (num[i]/100)%100, num[i]%100);
}

