#include <stdio.h>
#include <stdlib.h>

typedef struct date{
	int year;
	char month;
	char day;
}Date;

Date datelist[1000000] = {};

int cmp(const void* x, const void* y){
	Date* a = (Date*)x;
	Date* b = (Date*)y;
	if(a->year > b->year) return 1;
	if(a->year < b->year) return -1;	
	if(a->month > b->month) return 1;
	if(a->month < b->month) return -1;
	if(a->day > b->day) return 1;
	if(a->day < b->day) return -1;
	return 0;
}

int main(){
	int len;
	scanf("%d", &len);
	for(int i = 0; i < len; i++) scanf("%d%d%d", &datelist[i].year, &datelist[i].month, &datelist[i].day);
	qsort(datelist, len, sizeof(Date), cmp);
	for(int i = 0; i < len; i++) printf("%d %d %d\n", datelist[i].year, datelist[i].month, datelist[i].day);
    return 0;
}

