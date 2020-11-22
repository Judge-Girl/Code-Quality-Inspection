#include "constructPointerArray.h"

int location[1024*1024][2];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			location[A[i][j]][0] = i;
			location[A[i][j]][1] = j;
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(A[i][j]==N*N-1)
				B[i][j] = &(A[location[0][0]][location[0][1]]);
			else
				B[i][j] = &(A[location[A[i][j]+1][0]][location[A[i][j]+1][1]]);
		}
	}
}
