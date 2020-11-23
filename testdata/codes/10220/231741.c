#include<stdio.h>
#include<stdlib.h>
#define MAXN 1024
int pr[1024*1024+1] = {}, pc[1024*1024+1] = {};
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N)
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			pr[A[i][j]] = i;
			pc[A[i][j]] = j;
		}
	int size = N*N;
	for (i = 0; i < size; i++) {
		if (i == size-1) {
			B[pr[i]][pc[i]] = &A[pr[0]][pc[0]];
	    }
		else {
			B[pr[i]][pc[i]] = &A[pr[i+1]][pc[i+1]];
		}	
	}	
}
