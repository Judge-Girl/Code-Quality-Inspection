#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000000

int compare(const void* data1, const void* data2){
    unsigned long long* ptr1 = (unsigned long long*) data1;
    unsigned long long* ptr2 = (unsigned long long*) data2;
    return *ptr1 - *ptr2;
}
int main(){
    unsigned long long data[MAXN], Y, M , D;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++){
        scanf("%llu %llu %llu", &Y, &M, &D);
        data[i] = Y * 10000 + M * 100 + D;
    }
    qsort(data, n, sizeof(unsigned long long), compare);
    for (int i = 0; i < n; i ++){
        Y = (data[i]) / 10000;
        M = (data[i] % 10000) / 100;
        D = (data[i] % 100);
        printf("%llu %llu %llu\n", Y, M, D);
    }
}
