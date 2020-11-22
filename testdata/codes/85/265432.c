#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
typedef struct date{
  int year;
  int month;
  int day;
}Date;
Date A[MAX];
int compare(const void *data1,const void *data2){
  Date ptr1 = *(Date*)data1;
  Date ptr2 = *(Date*)data2;
  if(ptr1.year!=ptr2.year)
  return ptr1.year-ptr2.year;
  if(ptr1.month!=ptr2.month)
  return ptr1.month - ptr2.month;
  if(ptr1.day!=ptr2.day)
  return ptr1.day - ptr2.day;
}
int main(){
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  scanf("%d%d%d",&A[i].year,&A[i].month,&A[i].day);
  qsort(A,n,sizeof(Date),compare);
  for(i=0;i<n;i++)
  printf("%d %d %d\n",A[i].year,A[i].month,A[i].day);
  return 0;
}

