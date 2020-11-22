#include <stdio.h>
#include <stdlib.h>

typedef struct date{
	int year;
	int data;
}Date;

int compare(const void *a, const void *b){
	Date A = *(Date *)a;
	Date B = *(Date *)b;
	if(A.year > B.year)
		return 1;
	else if(A.year < B.year)
		return -1;
	else{
		if(A.data > B.data)
			return 1;
		else if(A.data < B.data)
			return -1;
	}
}

Date date[1000000];

int main (){
	int num;
	scanf("%d", &num);
	int month, day;
	for(int cnt = 0; cnt < num; cnt++){
		scanf("%d %d %d", &date[cnt].year, &month, &day);
		date[cnt].data = month * 100 + day;
	}
	qsort(date, num, sizeof(Date), compare);
	for(int cnt = 0; cnt < num; cnt++)
		printf("%d %d %d\n", date[cnt].year, date[cnt].data / 100, date[cnt].data % 100);
	return 0;
}

