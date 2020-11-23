#include<stdio.h>
#include<stdlib.h>

#define MAXN 1000001 
typedef struct{
    int year;
    short month, day;
}Date;


int cmp(const void* a, const void* b){
    Date *a1, *b1;
    b1 = (Date *) b;
    a1 = (Date *) a;
    if(a1 -> year > b1 -> year){
        return 1;
    }
    else if(a1 -> year < b1 -> year){
        return -1;
    }
    else{
        if(a1 -> month > b1 -> month){
            return 1;
        }
        else if( a1 -> month < b1 -> month){
            return -1;
        }
        else{
            if(a1 -> day > b1 -> day)
                return 1;
            else 
                return -1;
          
        }
    }
}

int main(){
    int n;
    Date dates[MAXN];

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %hd %hd", &dates[i].year, &dates[i].month, &dates[i].day);
    }
    qsort(dates, n, sizeof(Date), cmp);
    for(int i = 0; i < n; i++){
        printf("%d %hd %hd\n", dates[i].year, dates[i].month, dates[i].day);
    }
}
