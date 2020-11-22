#include <stdio.h>
#include <stdlib.h>
 
struct expense
{
    int year;
    short month,date;
};
 
typedef struct expense Ex;
 
int cmp(const void *a1,const void *a2){
    Ex *a,*b;
    a = (Ex *)a1;
    b = (Ex *)a2;
    if(a->year > b->year){
        return 1;
    }else if(a->year < b->year){
        return -1;
    }else {
        if(a->month > b->month){
            return 1;
        }else if(a->month < b->month){
            return -1;
        }else{
            if(a->date > b->date)
                return 1;
            else if(a->date < b->date)
                return -1;
            else{
                return 0;
            }
        }
    }
}
 
int main(){
    Ex a[1000000];
    int i = 0;
    int k;
    scanf("%d",&k);
    for(i = 0;i < k;i++){
        scanf("%d %hd %hd",&a[i].year,&a[i].month,&a[i].date);
    }
    qsort(a,i,sizeof(Ex),cmp);
    int j;
    for(j = 0;j < i;j++){
        printf("%d %hd %hd\n", a[j].year,a[j].month,a[j].date);
    }
}
