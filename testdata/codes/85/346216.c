#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct date{
	int year;
	int month;
	int day;
} date;
int cmp(const void *data1, const void *data2){
	date *d1=(date *)data1;
	date *d2=(date *)data2;
	if(d1->year>d2->year) return 1;
	else if(d1->year<d2->year) return -1;
	else if(d1->month>d2->month) return 1;
	else if(d1->month<d2->month) return -1;
	else if(d1->day>d2->day) return 1;
	else if(d1->day<d2->day) return -1;
	else return 0;
}
date d[1000000];
int main(){
	int n;
	char str[15], *ptr;
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		fgets(str, 15, stdin);
		ptr=strtok(str," ");
		d[i].year=atoi(ptr);
		ptr=strtok(NULL, " ");
		d[i].month=atoi(ptr);
		ptr=strtok(NULL, " ");
		d[i].day=atoi(ptr);
	}
	qsort(d, n, sizeof(date), cmp);
	for(int i=0;i<n;i++){
		printf("%d %d %d\n", d[i].year, d[i].month, d[i].day);
	}
	return 0;
}
