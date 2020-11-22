#include <stdio.h>
#include <stdlib.h>
int count[100000]={};
void split(int A[], int *a[], int *head[], int k){
int i=0;

while(a[i++]!=NULL);
int locale[k];
for(int j=0;j<i;j++)
{
if(count[A[j]%k]==0)
{head[A[j]%k]=&A[j];
locale[A[j]%k]=j;
}
count[A[j]%k]++;

}
for(int j=0;j<k;j++)
{
if(count[j]==0)
head[j]=NULL;

}
int temp;
for(int j=0;j<k;j++)
{if(count[j]==0)
continue;
    temp =locale[j];
    for(int g=locale[j];g<i;g++)
{
if(A[g]%k==j)
{

    a[temp]=&A[g];
    temp=g;
    count[j]--;
    if(count[j]==0)
    {break;}
}

}
a[temp]=NULL;
}


return ;




}
