#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define max 10000000
long long int date[max];

int compare(const void*ptr1,const void*ptr2)
{
    long long int *d1=(long long int *)ptr1;
    long long int *d2=(long long int *)ptr2;
    if(*d1<*d2)
    {
        return -1;
    }
    else if(*d1>*d2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long int y,m,d;
        scanf("%lld %lld %lld",&y,&m,&d);
        date[i]=y*10000+m*100+d;
    }
    qsort(&date[0], n, sizeof(long long int), compare);
    for(int i=0;i<n;i++)
    {
        printf("%llu %llu %llu\n",date[i]/10000,(date[i]%10000)/100,date[i]%100);
    }
    return 0;
}
