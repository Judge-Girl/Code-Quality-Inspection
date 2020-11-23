#include <stdio.h>
int loc[1048576] = {0};
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	for(int i =0; i < N; i++){
		for(int j = 0; j < N; j++){
			loc[A[i][j]] = i*N+j;
		}
	}
	for(int i = 0; i < N*N; i++){
		if(i == N*N-1)
			B[loc[i]/N][loc[i]%N] = &A[loc[0]/N][loc[0]%N];
		else
			B[loc[i]/N][loc[i]%N] = &A[loc[i+1]/N][loc[i+1]%N];
	}
}
