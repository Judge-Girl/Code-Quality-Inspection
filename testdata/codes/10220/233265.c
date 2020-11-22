#include <stdio.h>
#include "constructPointerArray.h"

int const *D[1048576] = {0};

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N) {
	// Scan A, store address of A[i+1] into i-th cell
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			D[A[i][j]] = &A[i][j];
#ifdef DEBUG
printf("array value: %d, array memory: %p\n", *D[A[i][j]], &A[i][j]);
#endif
		}
	}
	// Setup *B array
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int indexNum = ((A[i][j]+1) > ((N*N) - 1)) ? 0: A[i][j] + 1;
			B[i][j] = D[indexNum];
#ifdef DEBUG
printf("indexNum: %d, B[%d][%d]\n", indexNum, i, j);
#endif
		}
	}
}
