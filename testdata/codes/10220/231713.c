#include <stdio.h>
#define MAXN 1024
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    int i, j, value[1024 * 1024];
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            value[A[i][j]] = (i * N + j);
    for(i=0;i<N*N;i++){
        if(i == N*N - 1){
            B[value[i] / N][value[i] % N] = &A[value[0] / N][value[0] % N];
            break;
        }
        B[value[i] / N][value[i] % N] = &A[value[i+1] / N][value[i+1] % N];
    }
    return;
}
