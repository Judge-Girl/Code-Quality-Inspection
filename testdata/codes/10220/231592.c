#include <stdio.h>
#define MAXN 1024
int A[MAXN][MAXN];
const int *B[MAXN][MAXN];

void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
	int tmp[MAXN * MAXN];
	int i,j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			tmp[A[i][j]] = (i * N + j);
		}
	}
	for(i = 0; i < N * N - 1 ; i++){
		int row = tmp[i] / N;
		int col = tmp[i] % N;
		int nr = tmp[i + 1] / N;
		int nc = tmp[i + 1] % N;
		B[row][col] = &A[nr][nc];
	}
	B[tmp[N * N - 1] / N][tmp[N * N - 1] % N] = &A[tmp[0] / N][tmp[0] % N];
	return;
}
