#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k)
{
	int i, j;
	int N;
	int tail[k];

	for(i = 0; a[i] != NULL; i++);
	N = i + 1;

	for(i = 0; i < k; i++){
		head[i] = NULL;
		tail[i] = -1;
	}
	for(i = 0; i < N; i++){
		j = A[i] % k;
		if(tail[j] == -1){
			head[j] = &A[i];
			tail[j] = i;
		}
		else{
			a[tail[j]] = &A[i];
			tail[j] = i;
		}
	}

	for(i = 0; i < k; i++){
		if(tail[i] != -1)
			a[tail[i]] = NULL;
	}

}
