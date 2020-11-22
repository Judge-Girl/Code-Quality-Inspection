#include <stdio.h>

void split(int A[], int *a[], int *head[], int k)
{
	int **last[k];
	for (int i = 0; i < k; i++)
		last[i] = &head[i];
	int index = 0;
	while (index == 0 || a[index - 1] != NULL) {
		int mod = A[index] % k;
		*last[mod] = &A[index];
		last[mod] = &a[index];
		index++;
	}
	for (int i = 0; i < k; i++)
		*last[i] = NULL;
	return;
}
