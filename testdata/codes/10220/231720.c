#include <stdio.h>
#define MAXN 1024


int *ptrA[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    int i, j;


    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            ptrA[A[i][j]]=&A[i][j];
        }
    }
/*
    for(i=0; i<N*N; i++){
        printf("%d\n", ptrA[i]);
    }
*/
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(A[i][j]>=0 && A[i][j]<N*N-1){
                B[i][j]=ptrA[A[i][j]+1];
            }else{
                B[i][j]=ptrA[0];
            }
        }
    }


    return;
}

