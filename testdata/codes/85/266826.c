#include <stdio.h>
#include <stdlib.h>
#define M 1000000
struct D{
    int y, m, d;
};
typedef struct D D;
int c(const void* a, const void* b){
    D* d1 = (D*)a;
    D* d2 = (D*)b;
    if(d1->y < d2->y){
        return -1;
    }else if(d1->y > d2->y){
        return 1;
    }else if(d1->m < d2->m){
        return -1;
    }else if(d1->m > d2->m){
        return 1;
    }else if(d1->d < d2->d){
        return -1;
    }else if(d1->d > d2->d){
        return 1;
    }else{
        return 0;
    }
}
int n;
D ds[M];
int sz = sizeof(D);
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &ds[i].y, &ds[i].m, &ds[i].d);
    qsort(ds, n, sz, c);
    for (int i = 0; i < n; i++){
        printf("%d %d %d\n", ds[i].y, ds[i].m, ds[i].d);
    }
}
