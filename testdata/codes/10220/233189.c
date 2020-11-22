#include <stdio.h>
#include "constructPointerArray.h"
int A[MAXN][MAXN];
const int *B[MAXN][MAXN];
const int *D[1048576];
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input = A[i][j];
			D[input] = &A[i][j];
		}
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			int input = A[i][j];
			if (input != N*N-1)
				B[i][j] = D[input+1];
			else
				B[i][j] = D[0];
		}
	}
	
}
