#include "constructPointerArray.h"
int* arr[1024 * 1024 + 5];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[A[i][j]] = &A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			B[i][j] = arr[((A[i][j] + 1) % (N * N))];
		}
	}
}

