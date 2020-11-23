#include <stdio.h>
#include <stdlib.h>
 
 
int compare(const void *a, const void *b);
int dates[1<<20];
int main(void){
    int n;
    scanf("%d", &n);
    int year, month, day;
    for (int i = 0; i < n; i++){
        scanf("%d%d%d", &year, &month, &day);
        dates[i] = (year << 9) + (month << 5) + day;
    }
    qsort(dates, n, sizeof(int), &compare);
    for (int i = 0; i < n; i++){
        printf("%d ", (dates[i] >> 9));
        dates[i] &= 0x01ff;
        printf("%d ", dates[i] >> 5);
        dates[i] &= 0x001f;
        printf("%d\n", dates[i]);
    }
    return 0;
 
}
 
int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
