#include<stdio.h>
#include<stdlib.h>

void split(int A[],int *a[],int *head[],int k)
{
	int i,tail[k],r;

	for(i=0;i<k;i++)
	{
		tail[i]=-1;
	}

	i=0;
	while(a[i]!=NULL)
	{
		r=A[i]%k;
		if(tail[r]==-1)
		{
			head[r]=&A[i];
		}
		else
		{
			a[tail[r]]=&A[i];
		}
		tail[r]=i;
		i++;
	}
	r=A[i]%k;
	if(tail[r]==-1)
	{
		head[r]=&A[i];
	}
	else
	{
		a[tail[r]]=&A[i];
	}
	tail[r]=i;

	for(i=0;i<k;i++)
	{
		a[tail[i]]=NULL;
	}
}
