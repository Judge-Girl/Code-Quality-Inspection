#pragma GCC optimize("O3")
#include<stdio.h>

void merge(int A[],int B[],int* a[],int* b[])
{
	int n=0;
	while(a[n++]);
	int m=0;
	while(b[m++]);
	int i,p;
	for(i=0,p=0;i<m;i++)
	{
		while(p<n&&A[p]<B[i])
			p++;
		if(p)
		{
			if(!i||A[p-1]>B[i-1])
				a[p-1]=&B[i];
		}
		if(p!=n)
		{
			if(i==m-1||A[p]<B[i+1])
				b[i]=&A[p];
		}
	}
}
