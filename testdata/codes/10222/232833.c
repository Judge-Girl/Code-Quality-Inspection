
#include<stdio.h>
void split(int A[], int *a[], int *head[], int k)
{
	int x,alength,n=0;
	int **start;
	int tail[k];
	for(x=0;x<k;x++)
	tail[x]=-1;
	for(x=0;x<k;x++)
	head[x]=NULL;

	while(a[n]!=NULL)
	n++;
	alength=n;
    
    for(n=0;n<=alength;n++)
    {
    	if(tail[A[n]%k]==-1)
    	{
    		head[A[n]%k]=&A[n];
    		tail[A[n]%k]=n;
		}
		else
		{
			
    	a[tail[A[n]%k]]=&A[n];
    	tail[A[n]%k]=n;
		}
	}

	for(n=0;n<k;n++)
	{
		a[tail[n]]=NULL;
	}
}

