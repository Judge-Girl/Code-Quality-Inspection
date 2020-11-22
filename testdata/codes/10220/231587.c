#include <stdio.h>
#define MAXN 1024
int a[MAXN*MAXN][2];
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N)
{
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++){
            a[A[i][j]][0] = i;
            a[A[i][j]][1] = j;
        }
    for(i = 0; i < N * N - 1; i++){
        B[a[i][0]][a[i][1]] = &A[a[i + 1][0]][a[i + 1][1]];
    }
    B[a[i][0]][a[i][1]] = &A[a[0][0]][a[0][1]];
    return;
}
