#include <stdio.h>
#define MAXN 1024
const int *a[1024*1024];
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			a[A[i][j]] = &A[i][j];
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			B[i][j] = a[(A[i][j] + 1) % (N * N)];
		}
	}
}
