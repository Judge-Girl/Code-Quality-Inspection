#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int year;
    short int dd;
} Date;
Date a[1000000];
int cmp(const void *m, const void*n){
    Date *x = (Date*) m;
    Date *y = (Date*) n;
    if(x->year != y->year)
        return x->year - y->year;
    return x->dd - y->dd;
}
int main(){
    int n;
  	short int m,d;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++){
            scanf("%d %hd %hd", &a[i].year, &m, &d);
      		a[i].dd = 100*m+d;
    }
    qsort(a, n, sizeof(Date), cmp);
    for(int i = 0; i < n; i++)
        printf("%d %hd %hd\n", a[i].year, a[i].dd/100, a[i].dd%100);
    return 0;
    }
}

