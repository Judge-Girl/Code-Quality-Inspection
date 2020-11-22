#include <stdio.h>
void merge(int A[], int B[], int* a[], int* b[])
{
	int i, j, k, N, M;
	for(i = 0; a[i] != NULL; i++);
	N = i+1;
	for(i = 0; b[i] != NULL; i++);
	M = i+1;
	i = 0; j = 0;
	while(i < N && j < M){
		if(A[i] <= B[j]){
			if(i+1 < N && A[i+1] <= B[j]){
				a[i] = &A[i+1];
			}
			else
				a[i] = &B[j];
			i++;
		}
		else{
			if(j+1 < M && A[i] > B[j+1]){
				b[j] = &B[j+1];
			}
			else
				b[j] = &A[i];
			j++;
		}
	}

	if(i == N){
		for(k = j; k < M-1; k++){
			b[k] = &B[k+1];
		}
		b[M-1] = NULL;
	}
	if(j == M){
		for(k = i; k < N-1; k++){
			a[k] = &A[k+1];
		}
		a[N-1] = NULL;
	}
	
}
