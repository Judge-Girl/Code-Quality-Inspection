#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000000

typedef struct day{
	int year;
	short int month;
	short int date;
}Day;

Day array[MAXN];

int compare(const void *data1, const void *data2){
	Day *ptr1 = (Day *) data1;
    Day *ptr2 = (Day *) data2;
    if(ptr1 -> year < ptr2 -> year)
        return -1;
    else if(ptr1 -> year > ptr2 -> year)
        return 1;
    else if(ptr1 -> month < ptr2 -> month)
        return -1;
    else if(ptr1 -> month > ptr2 -> month)
        return 1;
    else if(ptr1 -> date < ptr2 -> date)
        return -1;
    else if(ptr1 -> date > ptr2 -> date)
        return 1;
    else
        return 0;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 5)
		scanf("%d%hd%hd%d%hd%hd%d%hd%hd%d%hd%hd%d%hd%hd", &array[i].year, &array[i].month, &array[i].date,
			&array[i + 1].year, &array[i + 1].month, &array[i + 1].date, &array[i + 2].year, &array[i + 2].month, &array[i + 2].date, 
			&array[i + 3].year, &array[i + 3].month, &array[i + 3].date, &array[i + 4].year, &array[i + 4].month, &array[i + 4].date);
	qsort(array, n, sizeof(Day), compare);
	for(int i = 0; i < n; i += 5)
		printf("%d %hd %hd\n%d %hd %hd\n%d %hd %hd\n%d %hd %hd\n%d %hd %hd\n", array[i].year, array[i].month, array[i].date,
			array[i + 1].year, array[i + 1].month, array[i + 1].date, array[i + 2].year, array[i + 2].month, array[i + 2].date, 
			array[i + 3].year, array[i + 3].month, array[i + 3].date, array[i + 4].year, array[i + 4].month, array[i + 4].date);
	return 0;
}
