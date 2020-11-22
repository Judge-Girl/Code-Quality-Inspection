#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int year;
    short int month, date;
} Date;
Date a[1000000];
int cmp(const void *m, const void*n){
    Date *x = (Date*) m;
    Date *y = (Date*) n;
    if(x->year != y->year)
        return x->year - y->year;
    if(x->month != y->month)
        return x->month - y->month;
    return x->date - y->date;
}
int main(){
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            scanf("%d %hd %hd", &a[i].year, &a[i].month, &a[i].date);
    }
    qsort(a, n, sizeof(Date), cmp);
    for(int i = 0; i < n; i++)
        printf("%d %hd %hd\n", a[i].year, a[i].month, a[i].date);
    return 0;
}

