#include<stdio.h>

#define MAXN 1024


int tmp[1048576][2];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	int k = 0;
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			tmp[A[i][j]][0] = i;
			tmp[A[i][j]][1] = j;
		}
	}
	
	for(int i = 0;i<N*N-1;i++){
		B[tmp[i][0]][tmp[i][1]] = &A[tmp[i+1][0]][tmp[i+1][1]];
	}
	B[tmp[N*N-1][0]][tmp[N*N-1][1]] = &A[tmp[0][0]][tmp[0][1]];
}

