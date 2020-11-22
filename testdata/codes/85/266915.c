#include <stdio.h>
#include <stdlib.h>
#define M 2000000
struct D{
    long long y, m, d;
};
typedef struct D D;
int c(const void *a, const void *b){
    long long *p1 = (long long *)a;
    long long *p2 = (long long *)b;
    if(*p1<*p2){
        return -1;
    }else if(*p1>*p2){
        return 1;
    }else{
        return 0;
    }
}
int n;
D ds[M];
long long t[M];
int sz = sizeof(long long);
int main()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        scanf("%lld%lld%lld", &ds[i].y, &ds[i].m, &ds[i].d);
        t[i] = ds[i].y * 10000 + ds[i].m * 100 + ds[i].d;
    }
    qsort(t, n, sz, c);
    for (int i = 0; i < n; i++){
        printf("%lld ",t[i]/10000);
        t[i]%=10000;
        printf("%lld %lld\n",t[i]/100,t[i]%100);
    }
}
