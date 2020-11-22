#include "split.h"
#include <stdio.h>
int **kmod[100000] = {NULL};
void split(int A[], int *a[], int *head[], int k)
{
	int len = 0;
	while(a[len] != NULL)
	{
		a[len] = NULL;
		len++;
	}
	for(int i = 0; i <= len; i++)
	{
		int x = A[i] % k;
		if(kmod[x] == NULL)
		{
			kmod[x] = &(a[i]);
			head[x] = &(A[i]);
		}
		else
		{
			*kmod[x] = &(A[i]);
			kmod[x] = &(a[i]);
		}
	}
}
