#include<stdio.h>
#include"constructPointerArray.h"
int x[1024*1024-1], y[1024*1024-1];

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			x[A[i][j]] = i;
			y[A[i][j]] = j;
		}
	for(int i = 0; i < N*N-1; i++){
		B[x[i]][y[i]] = &A[x[i+1]][y[i+1]];
	}
	B[x[N*N-1]][y[N*N-1]] = &A[x[0]][y[0]];
	return;
}
