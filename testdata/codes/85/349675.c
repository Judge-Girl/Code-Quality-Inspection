#include<stdio.h>
#include<stdlib.h>

int compare(const void *data1, const void *data2){
    long long *ptr1 = (long long *)data1;
    long long *ptr2 = (long long *)data2;
    if(*ptr1 > *ptr2){
        return 1;
    } else if(*ptr1 < *ptr2){
        return -1;
    }
    return 0;
}

long long date[1000000];

int main(void){
    int N;
    scanf("%d", &N);
    long long a, b, c;
    for (int i = 0; i < N; i++){
        scanf("%lld", &a);
        scanf("%lld", &b);
        scanf("%lld", &c);
        date[i] = 10000 * a + 100 * b + c;
    }
    qsort(date, N, sizeof(long long), compare);
    for (int i = 0; i < N; i++){
        printf("%lld %lld %lld\n", date[i] / 10000, (date[i] / 100) % 100, date[i] % 100);
    }
    return 0;
}
