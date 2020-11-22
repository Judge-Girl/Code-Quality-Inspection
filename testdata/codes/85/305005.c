#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Date {
        unsigned int year :22;
        unsigned int month : 4 ;
        unsigned int day :6;
};
typedef struct Date date;

int compare(const void *data1, const void *data2){

    date *ptr1 = (date *)data1;
    date *ptr2 = (date *)data2;
    if ( ptr1->year < ptr2->year ) return -1;
    else if ( ptr1->year > ptr2->year ) return 1;
    else {
        if ( ptr1->month < ptr2->month ) return -1;
        else if ( ptr1->month > ptr2->month ) return 1;
        else {
            if ( ptr1->day < ptr2->day ) return -1;
            else if ( ptr1->day > ptr2->day ) return 1;
            else return 0;
        }
    }
}

int main() {
        date n[1000000];
        int number;
        scanf("%d",&number);
        int year,month,day;
        for( int i = 0 ; i < number ; i++ ){

            scanf("%u %u %u",&year,&month,&day);
            n[i].year = year;
            n[i].month = month;
            n[i].day = day;

        }
        qsort( n , number , sizeof(date) , compare);

        for( int i = 0 ; i < number ; i++ )
            printf("%u %u %u\n",n[i].year,n[i].month,n[i].day);


        return 0;
}

