#include <stdio.h>
int *ptr[1024 * 1024];
void constructPointerArray(int A[1024][1024], int *B[1024][1024], int N)
{
int i, j, k;
for(i = 0; i < N; i ++)
for(j = 0; j < N; j ++)
ptr[A[i][j]] = &A[i][j];
for(i = 0; i < N; i ++)
for(j = 0; j < N; j ++){
B[i][j] = ptr[(A[i][j]+1)%(N*N)];
}
}
