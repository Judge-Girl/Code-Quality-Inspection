#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int year;
	int month;
	int day;
} Date;

int compare(const void *ptr1, const void *ptr2)
{
	Date *dptr1 = (Date *)ptr1;
	Date *dptr2 = (Date *)ptr2;

	int dy = dptr1->year - dptr2->year;
	int dm = dptr1->month - dptr2->month;
	int dd = dptr1->day - dptr2->day;
	return dy == 0 ? (dm == 0 ? dd : dm) : dy;
}

#define MAX 1000000
Date date[MAX];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &date[i].year, &date[i].month, &date[i].day);
	qsort(date, n, sizeof(Date), compare);
	for (int i = 0; i < n; i++)
		printf("%d %d %d\n", date[i].year, date[i].month, date[i].day);
	return 0;
}

