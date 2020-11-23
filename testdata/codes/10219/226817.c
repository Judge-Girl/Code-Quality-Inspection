#pragma GCC optimize("O3")
#include<stdio.h>

void merge(int A[],int B[],int* a[],int* b[])
{
	int n=0;
	while(a[n++]);
	int m=0;
	while(b[m++]);
	int i=0,j=0;
	while(i<n&&j<m)
	{
		if(A[i]<B[j])
		{
			if(i==n-1||B[j]<A[i+1])
				a[i]=&B[j];
			++i;
		}
		else
		{
			if(j==m-1||A[i]<B[j+1])
				b[j]=&A[i];
			++j;
		}
	}
}
