#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int year,month,day;
}date;

int cmp( const void *a, const void *b){
	date val1 = *(date *)a;
	date val2= *(date *)b;

	if (val1.year!=val2.year) return val1.year - val2.year;
	if (val1.month!=val2.month) return val1.month-val2.month;
	if (val1.day!=val2.day) return val1.day-val2.day;
	return 0;
}

date arr[1000005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&arr[i].year,&arr[i].month,&arr[i].day);
	}
	qsort(arr,n,sizeof(date),cmp);
	for (int i=0;i<n;i++)printf("%d %d %d\n", arr[i].year,arr[i].month,arr[i].day);
	return 0;
}
