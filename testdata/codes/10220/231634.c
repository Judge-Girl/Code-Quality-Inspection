#include<stdio.h>
#define MAXN 1024

int numr[MAXN*MAXN];
int numc[MAXN*MAXN];

void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N)
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            numr[A[i][j]] = i;
            numc[A[i][j]] = j;
        }
    }
    for(int i = 0; i < N*N-1; i++){
        B[numr[i]][numc[i]] = &A[numr[i+1]][numc[i+1]];
    }
    B[numr[N*N-1]][numc[N*N-1]] = &A[numr[0]][numc[0]];
}

