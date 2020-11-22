#include <stdio.h>
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    const int **b = malloc(sizeof(const int*) * N*N);
    for(int i = 0; i < N; i++){
       for(int j = 0; j < N; j++){
           b[A[i][j]] = &A[i][j];
       }
    }
    //for(int i = 0;i<N*N;i++) printf("%d ",*b[i]);
    for(int i = 0; i < N; i++){
       for(int j = 0; j < N; j++){
           if(A[i][j]+1 == N*N) B[i][j] = b[0];
           else B[i][j] = b[A[i][j]+1];
       }
   }
}
