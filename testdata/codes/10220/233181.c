#include <stdio.h>
#include "constructPointerArray.h"
int numi[1024*1024], numj[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    int i, j, k, l, m;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            k = A[i][j];
            B[i][j] = &A[i][j];
            numi[k] = i;
            numj[k] = j;
        }
    }
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            k = *B[i][j];
            if(k == N*N-1){
                l = numi[0];
                m = numj[0];
                B[i][j] = &A[l][m];
            }
            else{
                l = numi[k+1];
                m = numj[k+1];
                 B[i][j] = &A[l][m];
            }
 
        }
    }
}

