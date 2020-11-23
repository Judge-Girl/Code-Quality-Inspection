#include <stdio.h>
#include <stdlib.h>
#define MAXN 1024
int x[1024 * 1024]={0};
int y[1024 * 1024]={0};
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{int count=0,i,j,g=0,x1,y1,x2,y2;
for(i=0;i<N;i++)
for(j=0;j<N;j++)
    {g=A[i][j];
x[g]=j;
y[g]=i;}
 
y1=0;
x1=0;
x2=1;
y2=1;
        while(count<N*N)
        {if(count==N*N-1)
        {B[y[y1]][x[x1]]=&(A[y[0]][x[0]]);}
        else
            B[y[y1]][x[x1]]=&(A[y[y2]][x[x2]]);
          count++;
          x1++;
          y1++;
          x2++;
          y2++;
}}
