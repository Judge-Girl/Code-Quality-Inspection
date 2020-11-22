#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int A[], int B[], int* a[], int* b[])
{
	int **tmp;
	int *tem = malloc(sizeof(int));
	tmp = &tem;
	int m = 0, n = 0;
	while (a[m] != NULL && b[n] != NULL)
	{
		if (A[m] < B[n])
		{
			*tmp = &A[m];
			tmp = &a[m];
			m++;
		}
		else
		{
			*tmp = &B[n];
			tmp = &b[n];
			n++;
		}
	}
	if (a[m] == NULL)
	{
		while (b[n] != NULL)
		{
			if (B[n] < A[m])
			{
				*tmp = &B[n];
				tmp = &b[n];
			}
			else
			{
				*tmp = &A[m];
				a[m] = &B[n];
				return;
			}
			n++;
		}
		if (A[m] < B[n])
		{
			*tmp = &A[m];
			a[m] = &B[n];
		}
		else
		{
			*tmp = &B[n];
			b[n] = &A[m];
		}
	}
	else
	{
		while (a[m] != NULL)
		{
			if (B[n] > A[m])
			{
				*tmp = &A[m];
				tmp = &a[m];
			}
			else
			{
				*tmp = &B[n];
				b[n] = &A[m];
				return;
			}
			m++;
		}
		if (A[m] < B[n])
		{
			*tmp = &A[m];
			a[m] = &B[n];
		}
		else
		{
			*tmp = &B[n];
			b[n] = &A[m];
		}
	}
	return;
}

#ifdef RUN
int main(int argc, char const *argv[])
{
	int A[10], B[10];
    int *a[10], *b[10], *ans_a[10], *ans_b[10];
    int i, N, M;
 
    scanf("%d%d", &N, &M);
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(i = 0; i < M; i++)
        scanf("%d", &B[i]);
    for(i = 0; i < N-1; i++)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for(i = 0; i < M-1; i++)
        b[i] = &B[i+1];
    b[M-1] = NULL;
 
    merge(A, B, a, b);
 
    for(i = 0; i < N; i++){
        if (a[i] != NULL)
        	printf("%d ", *a[i]);
    }
    printf("\n");
    for(i = 0; i < M; i++){
    	if (b[i] != NULL)
        	printf("%d ", *b[i]);
    }
    printf("\n");
    printf("Finish!\n");
	return 0;
}
#endif
