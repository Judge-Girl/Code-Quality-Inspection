#include <stdio.h>
#include <stdlib.h>

typedef struct dates{
	int year;
	short month;
	short day;
}Date;

int compare(const void *data1, const void *data2){
	struct dates *ptr1 = (struct dates *)data1;
	struct dates *ptr2 = (struct dates *)data2;
	if (ptr1->year < ptr2->year)	return -1;
	else if (ptr1->year > ptr2->year)	return 1;
	else{
		if (ptr1->month < ptr2->month)	return -1;
		else if (ptr1->month > ptr2->month)	return 1;
		else{
			if (ptr1->day < ptr2->day)	return -1;
			else return 1;
		}
	}
}

int main(){
	int n;
	scanf ("%d", &n);
	Date date[n];
	int i;
	for (i = 0; i < n; i++){
		scanf ("%d%hd%hd", &(date[i].year), &(date[i].month), &(date[i].day));
	}
	qsort(date, n, sizeof(Date), compare);
	for (i = 0; i < n; i++){
		printf ("%d %hd %hd\n", date[i].year, date[i].month, date[i].day);
	}
	return 0;
}
