#include <stdio.h>
#include <stdlib.h>

long long arr[1000000];
int compare(const void *a, const void *b)
{
    long long *ptr1 = (long long *)a;
    long long *ptr2 = (long long *)b;
    if(*ptr1 > *ptr2)
        return 1;
    return -1;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        long long temp1,temp2,temp3;
        scanf("%lld%lld%lld", &temp1, &temp2, &temp3);
        arr[i] = temp1 * 32 * 13 + temp2 * 32 + temp3;
    }
    qsort(arr, n, sizeof(long long), compare);
    for(int i = 0; i < n; i++){
        long long temp1 = arr[i] / 416;
        long long temp2 = arr[i] % 416 / 32;
        long long temp3 = arr[i] % 32;
        printf("%lld %lld %lld\n", temp1, temp2, temp3);
    }
}

