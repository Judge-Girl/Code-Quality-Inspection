#include<stdio.h>
#define MAXN 1024
int row[MAXN * MAXN] = {}, col[MAXN * MAXN] = {};
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			row[A[i][j]] = i;
			col[A[i][j]] = j;
		}
	}
	for(i = 0; i < N * N - 1; i++)
		B[row[i]][col[i]] = &A[row[i + 1]][col[i + 1]];
	B[row[N * N - 1]][col[N * N - 1]] = &A[row[0]][col[0]];
	return;
}

