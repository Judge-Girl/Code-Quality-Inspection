#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct date{
	int32_t year;
	int8_t month, day;
}Date;

int cmp(const void *data1, const void *data2){
	Date *date1 = (Date *)data1;
	Date *date2 = (Date *)data2;
	if(date1->year < date2->year)
		return -1;
	else if(date1->year > date2->year)
		return 1;
	else if(date1->month < date2->month)
		return -1;
	else if(date1->month > date2->month)
		return 1;
	else if(date1->day < date2->day)
		return -1;
	else if(date1->day > date2->day)
		return 1;
	return 0;		
}

Date dates[1000000];
int main(void){
	long int n;
	scanf("%ld", &n);
	for(long int i = 0; i < n; i++)
		scanf("%u%d%d", &dates[i].year, &dates[i].month, &dates[i].day);

	qsort(dates, n, sizeof(Date), cmp);

	for(long int i = 0; i < n; i++)
		printf("%u %d %d\n", dates[i].year, dates[i].month, dates[i].day);
	return 0;
}
