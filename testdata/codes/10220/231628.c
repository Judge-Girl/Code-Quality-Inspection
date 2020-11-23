#include <stdio.h>
#define MAXN 1024
int *Adrs[MAXN*MAXN];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Adrs[A[i][j]] = &A[i][j];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) {
			B[i][j] = Adrs[(A[i][j] + (N * N) + 1) % (N * N)];
		}
}
