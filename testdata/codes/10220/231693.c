#include <stdio.h>
#include "constructPointerArray.h"

const int *Aorder[1024*1024];

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			Aorder[ A[i][j] ] = &A[i][j];
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(A[i][j]!=N*N-1)
				B[i][j]= Aorder[ A[i][j]+1];
			else
				B[i][j]= Aorder[0];
		}
	}
}
