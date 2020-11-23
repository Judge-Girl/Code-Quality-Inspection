#include <stdio.h>

#ifndef CONSTRUCT
#define CONSTRUCT
#define MAXN 1024
int position[MAXN * MAXN] = {};
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N)
{
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			position[A[i][j]] = i * N + j;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int n_B = position[(i * N + j) % (N * N)];
			int n_A = position[(i * N + j + 1) % (N * N)];
			B[n_B / N][n_B % N] = &A[n_A / N][n_A % N];
		}

	return;
}
#endif
