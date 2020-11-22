#include <stdio.h>
#include "constructPointerArray.h"
int pos[MAXN*MAXN][2] = { 0 };
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            pos[A[i][j]][0] = i;
            pos[A[i][j]][1] = j;
        }
    }
    for(int i=0; i+1<N*N; i++){
        B[pos[i][0]][pos[i][1]] = &A[pos[i+1][0]][pos[i+1][1]];
    }
    B[pos[N*N-1][0]][pos[N*N-1][1]] = &A[pos[0][0]][pos[0][1]];
}
