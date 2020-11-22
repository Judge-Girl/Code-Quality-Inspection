#include <stdio.h>
#define MAXN 1024
const int* D[MAXN*MAXN];
int tempi[MAXN*MAXN], tempj[MAXN*MAXN];
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			D[A[i][j]] = &(A[i][j]);
			tempi[A[i][j]] = i;
			tempj[A[i][j]] = j;
		}
	}

	for (int i = 0; i < N*N-1; ++i){
		B[tempi[i]][tempj[i]] = D[i+1];
	}

	B[tempi[N*N-1]][tempj[N*N-1]] = D[0];
}
