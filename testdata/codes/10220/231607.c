#include "constructPointerArray.h"
const int *C[MAXN*MAXN];

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			C[A[i][j]] = &A[i][j];
#ifdef DEDUG	
	for (int i = 0; i < N * N; i++)
            printf("%d ", *(C[i]));
    printf("\n");
#endif
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			B[i][j] = C[(A[i][j] + 1) % (N * N)];

	return;
}
