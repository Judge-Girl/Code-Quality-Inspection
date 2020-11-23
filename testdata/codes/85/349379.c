#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxl 1000000 



int cmp( const void *data1,const void *data2){
    long long int *ptr1=(long long int *)data1;
   long long int *ptr2=(long long int *)data2;
    if( *ptr1 < *ptr2 )
        return -1;
    if( *ptr1 > *ptr2)
        return 1;
    return 0;
}
long long int a[maxl];
int main(){
    
    int count=0;
    scanf("%d",&count);
    long long int tempa,tempb,tempc;
    for(int i=0;i<count;i++){
        scanf("%lld %lld %lld",&tempa,&tempb,&tempc);
        a[i]=tempa*10000+tempb*100+tempc;
    }

    qsort(a,count,sizeof(long long int ),cmp);
    for(int i=0;i<count;i++)
     printf("%lld %lld %lld\n",a[i]/10000,(a[i]%10000)/100,a[i]%100);
    return 0;
}
