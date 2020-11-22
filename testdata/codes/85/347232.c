#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    
    int n;
    scanf("%d", &n);
    long dates[1000000];
    for(int i=0;i<n;i++)
    {
        long year, month, day;
        scanf("%ld %ld %ld", &year, &month, &day);
        dates[i] = year*10000+month*100+day;
    }
    qsort(dates, n, sizeof(long long), cmp);
    for(int i=0;i<n;i++)
    {
        fprintf(stdout,"%ld %ld %ld\n", dates[i]/10000, dates[i]/100%100, dates[i]%100);
    }
}
