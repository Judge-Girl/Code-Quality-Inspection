#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
typedef struct date {
	int year;
	int month;
	int day;
} Date;

int Compare(const void *d1, const void *d2)
{
	Date *date1 = *((Date **)d1);
	Date *date2 = *((Date **)d2);
	if (date1->year > date2->year)
		return 1;
	else if (date1->year < date2->year)
		return -1;
	else if (date1->month > date2->month)
		return 1;
	else if (date1->month < date2->month)
		return -1;
	else if (date1->day > date2->day)
		return 1;
	else if (date1->day < date2->day)
		return -1;
	else
		return 0;
}

Date dates[MAX] = {0};
Date *dates_ptr1[MAX] = {0};
Date *dates_ptr2[MAX] = {0};
int len1 = 0, len2 = 0;

int main(void)
{
	int len = 0;
	scanf("%d", &len);
	scanf("%d%d%d", &(dates[0].year), &(dates[0].month), &(dates[0].day));
	dates_ptr2[len2++] = &(dates[0]);
	int gap = dates[0].year;
	for (int i = 1; i < len; i++) {
		scanf("%d%d%d", &(dates[i].year), &(dates[i].month), &(dates[i].day));
		if (dates[i].year < gap)
			dates_ptr1[len1++] = &(dates[i]);
		else
			dates_ptr2[len2++] = &(dates[i]);
	}
	qsort(dates_ptr1, len1, sizeof(Date *), Compare);
	qsort(dates_ptr2, len2, sizeof(Date *), Compare);
	for (int i = 0; i < len1; i++)
		printf("%d %d %d\n", dates_ptr1[i]->year, dates_ptr1[i]->month, dates_ptr1[i]->day);
	for (int i = 0; i < len2; i++)
		printf("%d %d %d\n", dates_ptr2[i]->year, dates_ptr2[i]->month, dates_ptr2[i]->day);
	return 0;
}

