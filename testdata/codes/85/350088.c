#include <stdio.h>
#include <stdlib.h>
 
typedef struct date{
    int year;
    short int month, day;
} Date;
 
int compare(const void *a, const void *b)
{
    Date *ptr1 = (Date *)a;
    Date *ptr2 = (Date *)b;
    if (ptr1->year < ptr2->year)
        return -1;
    else if (ptr1->year == ptr2->year) {
        if (ptr1->month < ptr2->month)
            return -1;
        else if (ptr1->month == ptr2->month) {
            if (ptr1->day < ptr2->day)
                return -1;
            else if (ptr1->day == ptr2->day)
                return 0;
            else
                return 1;
        }
        else
            return 1;
    }
    else
        return 1;
}
 
int main()
{
    int n;
    scanf("%d", &n);
    Date dates[1000000];
    for (int i = 0; i < n; i++) 
        scanf("%d%hd%hd", &dates[i].year, &dates[i].month, &dates[i].day);
    qsort(dates, n, sizeof(Date), compare);
    for (int i = 0; i < n; i++) 
        printf("%d %hd %hd\n", dates[i].year, dates[i].month, dates[i].day);
}
