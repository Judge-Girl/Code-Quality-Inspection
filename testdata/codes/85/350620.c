#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date{
	int year,month,day;
} data;

int compare(const void *a,const void *b)
{
//	data coma=*(data*)a;
//	data comb=*(data*)b;
	data *coma=(data*)a;
	data *comb=(data*)b;
/*	if(coma->year>comb->year)
		return 1;
	else if(coma->year<comb->year)
		return -1;
	else if(coma->month>comb->month)
		return 1;
	else if(coma->month<comb->month)
		return -1;
	else if(coma->day>comb->day)
		return 1;
	else if(coma->day<comb->day)
		return -1;
	return 0;*/
	if(coma->year!=comb->year)
		return(coma->year-comb->year);
	else if(coma->month!=comb->month)
		return(coma->month-comb->month);
	else return(coma->day-comb->day);
}
data now[1000000];
int main()
{
	//data now[100000];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&now[i].year,&now[i].month,&now[i].day);
	qsort(now,n,sizeof(data),compare);
	for(i=0;i<n;i++)
		printf("%d %d %d\n",now[i].year,now[i].month,now[i].day);
}

