#include<stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k)
{
	
	int i = 0;
	for (i = 0; i < k; i++)
		head[i] = NULL;
	int track[k];
	for (i = 0; i < k; i++)
		track[i] = 0;
	i = 0;
	while (a[i] != NULL)
	{
		int r = A[i] % k;
		if (head[r] == NULL)
		{
			head[r] = &A[i];
			track[r] = i;
		}
		else
		{
			a[track[r]] = &A[i];
			track[r] = i;
		}
		i++;
	}
	int r = A[i] % k;
	if (head[r] == NULL)
	{
		head[r] = &A[i];
		track[r] = i;
	}
	else
	{
		a[track[r]] = &A[i];
		track[r] = i;
	}
	for (i = 0; i < k; i++)
	{
		if (head[i] != NULL)
			a[track[i]] = NULL;
	}
	
}
