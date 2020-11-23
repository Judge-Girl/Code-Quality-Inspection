#include <stdio.h>
#include "constructPointerArray.h"
int A[MAXN][MAXN];
const int *B[MAXN][MAXN];
int *add[1024][1024];
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            int r=A[i][j]/N;
            int c=A[i][j]%N;
            add[r][c]=&A[i][j];
        }
    }

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            int r=(A[i][j]+1)/N;
            int c=(A[i][j]+1)%N;
            if(A[i][j]==N*N-1){r=0;c=0;}
            B[i][j]=add[r][c];
        }
    }

}
