#include <stdio.h>
#include <stdlib.h>
 
typedef struct date{
    int year;
    int month;
    int day;
}date;

void scan(int* x)
{
	int f=1;*x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){(*x)=(*x)*10+s-'0';s=getchar();}
	(*x)*=f;
}
 
int sort(const void* a, const void *b){
    if(((date*)a)->year > ((date*)b)->year)
        return 1;
    else if(((date*)a)->year < ((date*)b)->year)
        return -1;
    else if(((date*)a)->month > ((date*)b)->month)
        return 1;
    else if(((date*)a)->month < ((date*)b)->month)
        return -1;
    return (((date*)a)->day - ((date*)b)-> day);
}
date in[1000000];
int main(){
    int n;
    scanf("%d", &n);
 
    for(int i=0;i<n;i++){
        scan( &in[i].year);scan (&in[i].month);scan(&in[i].day);
    }
    qsort(in, n, sizeof(date), sort);
    for(int i=0;i<n;i++)
        printf("%d %d %d\n", in[i].year, in[i].month, in[i].day);
    return 0;
}
