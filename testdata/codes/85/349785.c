#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000000

typedef struct date{
	int year;
	short month;
	short day;
}Date;
Date dates[MAXNUM];
int cmp(const void *a ,const void *b){
	Date *l = (Date *)a;
	Date *r = (Date *)b;

	if(l->year > r->year){
		return 1;
	}
	else if(l->year < r->year){
		return -1;
	}
	else{
		if(l->month > r->month){
			return 1;
		}
		else if(l->month < r->month){
			return -1;
		}
		else{
			if(l -> day > r -> day)
                return 1;
            else if(l -> day < r -> day)
                return -1;
            else return 0;
		}
	}

	
}


	

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++)
		scanf("%d%hd%hd",&dates[i].year,&dates[i].month,&dates[i].day);
	qsort(dates,n,sizeof(Date),cmp);
	for(int i = 0; i < n; i++)
		printf("%d %hd %hd\n", dates[i].year, dates[i].month, dates[i].day);

	return 0;
}
