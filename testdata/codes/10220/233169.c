#include <stdio.h>
#define MAXN 1024

int position[1024*1024][2];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
   
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            position[A[i][j]][0] = i;
            position[A[i][j]][1] = j;
        }
    }     
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (A[i][j] != 0){
                B[position[A[i][j]-1][0]][position[A[i][j]-1][1]] = &A[i][j];
            }
            else {
                B[position[N*N-1][0]][position[N*N-1][1]] = &A[i][j];
            }
        }
    }
}   
    

