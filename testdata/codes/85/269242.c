#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long int ULL;

ULL date[1000000];

int compare(const void *x, const void *y)
{
	ULL *a = (ULL *)x, *b = (ULL *)y;
	if(*a > *b) return 1;
	return -1;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int c=0;c<n;c++){
		ULL year, month, day;
		scanf("%llu%llu%llu", &year, &month, &day);
		date[c] = year*10000 + month*100 + day;
	}
	qsort(date, n, sizeof(ULL), compare);
	for(int c=0;c<n;c++){
		ULL year = date[c]/10000, day = date[c]%100;
		ULL month = (date[c]-year*10000-day)/100;
		printf("%llu %llu %llu\n", year, month, day);
	}

}
