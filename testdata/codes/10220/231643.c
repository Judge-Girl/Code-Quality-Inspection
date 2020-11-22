#include <stdio.h>
#include "constructPointerArray.h"
int store[1024*1024][2]={{0}};
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			store[(A[i][j]+N*N-1)%(N*N)][0]=i;
			store[(A[i][j]+N*N-1)%(N*N)][1]=j;
		}
	}
	/*for (int i=0; i<N*N; i++){
		printf("%d %d\n", store[i][0], store[i][1]);
	}*/
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			B[i][j]=&A[store[A[i][j]][0]][store[A[i][j]][1]];
			//printf("%d\n", *B[i][j]);
		}
	}
	return;
}
