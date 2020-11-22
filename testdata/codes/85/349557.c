#include <stdio.h>
#include <stdlib.h>
#define nMAX 1000000

typedef struct _date{
    int year;
    int month;
    int day;
}Date;

int cmp(const void*data1,const void*data2){
    Date **ptr1=(Date **)data1;
    Date **ptr2=(Date **)data2;
    if((*ptr1)->year != (*ptr2)->year)
        return ((*ptr1)->year)-((*ptr2)->year);
    else if((*ptr1)->month!=(*ptr2)->month)
        return ((*ptr1)->month)-((*ptr2)->month);
    else
        return ((*ptr1)->day)-((*ptr2)->day);
}

Date dates[nMAX];
Date* ptr_dates[nMAX];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&(dates[i].year),&(dates[i].month),&(dates[i].day));
        ptr_dates[i]=&dates[i];
    }
    qsort(ptr_dates,n,sizeof(Date*),cmp);
    for(int i=0;i<n;i++){
        printf("%d %d %d\n",ptr_dates[i]->year,ptr_dates[i]->month,ptr_dates[i]->day);
    }
    return 0;
}
