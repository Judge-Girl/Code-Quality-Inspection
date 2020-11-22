#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000
 
int n, y, m, d;
int a[SIZE];
 
int cmp(const int *a, const int *b){
    return *a - *b;
}
 
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &y, &m, &d);
        a[i] = 416 * y + 32 * m + d;
    }
 
    qsort(a, n, sizeof(int), cmp);
 
    for(int i = 0; i < n; i++)
        printf("%d %d %d\n", a[i]/416, (a[i]%416)/32, (a[i]%416)%32);
 
    return 0;
}
