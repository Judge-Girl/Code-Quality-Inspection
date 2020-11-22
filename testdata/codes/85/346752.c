#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXN 1000000
typedef struct date{
	int year;
	uint8_t month;
	uint8_t day;
}Date;

int compare(const void *data1, const void *data2){
	Date *ptr1 = (Date *)data1;
	Date *ptr2 = (Date *)data2;
	if(ptr1 -> year < ptr2 -> year)
		return -1;
	else if(ptr1 -> year > ptr2 -> year)
		return 1;
	else if(ptr1 -> month < ptr2 -> month)
		return -1;
	else if(ptr1 -> month > ptr2 -> month)
		return 1;
	else if(ptr1 -> day < ptr2 -> day)
		return -1;
	else if(ptr1 -> day > ptr2 -> day)
		return 1;
	else 
		return 0;
}


int main(){
	int n;
	scanf("%d", &n);
	Date calendar[MAXN];
	for(int i = 0; i < n; i++){
		scanf("%d%hhu%hhu", &calendar[i].year, &calendar[i].month, &calendar[i].day);
	}
	qsort(calendar, n, sizeof(Date), compare);
	for(int i = 0; i < n; i++){
		printf("%d %hhu %hhu\n", calendar[i].year, calendar[i].month, calendar[i].day);
	}
	return 0;
}
