#include <stdio.h>
#include <stdlib.h>
 
#define MAX_NUMBER_OF_DATE 1000000
 
struct Date
{
    int year;
    char month , day;
};
 
typedef struct Date Date;
 
int compare(const void *data_1 , const void *data_2)
{
    Date *date_1 = (Date *)data_1 , *date_2 = (Date *)data_2;
 
    if (date_1->year < date_2->year ||
        (date_1->year == date_2->year && date_1->month < date_2->month) ||
        (date_1->year == date_2->year && date_1->month == date_2->month && date_1->day < date_2->day))
        return -1;
    else if (date_1->year > date_2->year ||
        (date_1->year == date_2->year && date_1->month > date_2->month) ||
        (date_1->year == date_2->year && date_1->month == date_2->month && date_1->day > date_2->day))
        return 1;
    else
    	return 0;
}
 
int main(int argc , char **argv)
{
    int number_of_date;
    Date date[MAX_NUMBER_OF_DATE];
 
    scanf("%d" , &number_of_date);
    for (int i = 0 ; i < number_of_date ; i++)
        scanf("%d%d%d" , &(date[i].year) , &(date[i].month) , &(date[i].day));
 
    qsort(date , number_of_date , sizeof(Date) , compare);
 
    for (int i = 0 ; i < number_of_date ; i++)
        printf("%d %d %d\n" , date[i].year , date[i].month , date[i].day);
 
    return 0;
}
