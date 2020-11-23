#include <stdio.h>
#define MAXN 1024
int D[MAXN*MAXN];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			D[A[i][j]] = i*N+j;
		}
	}

	for(int i=0;i<N*N;i++){
		int ptr_i = D[i] / N;
		int ptr_j = D[i] % N;
		int ptr_i2 = D[(i+1)%(N*N)] / N;
		int ptr_j2 = D[(i+1)%(N*N)] % N;
		B[ptr_i][ptr_j] = &A[ptr_i2][ptr_j2];
	}
}

