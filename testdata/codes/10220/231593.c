#include "constructPointerArray.h"

const int* record[MAXN*MAXN+5];

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			record[A[i][j]] = &A[i][j];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			B[i][j] = record[(A[i][j]+1)%(N*N)];
}
