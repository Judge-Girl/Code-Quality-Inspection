#include <stdio.h>
#define MAXN 1024

int x[MAXN * MAXN], y[MAXN * MAXN];

void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N) {
	int i, j, k;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			x[A[i][j]] = i;
			y[A[i][j]] = j;
		}
	}
	
	for (k = 0; k < N * N - 1; k++) {
		B[(x[k])][(y[k])] = &(A[(x[k + 1])][(y[k + 1])]);
	}
	B[(x[N * N - 1])][(y[N * N - 1])] = &(A[(x[0])][(y[0])]);
	
	
	return;
}

