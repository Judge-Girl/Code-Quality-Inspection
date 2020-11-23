#include <stdio.h>
#define MAXN 1024
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    int i, j, value[1024 * 1024];
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            value[A[i][j]] = (i * N + j);
    for(i=0;i<N*N;i++){
        if(i == N*N - 1){
            int x = value[i] / N, y = value[i] % N;
            B[x][y] = &A[value[0] / N][value[0] % N];
            break;
        }
        else{
            int x = value[i] / N, y = value[i] % N;
            int x2 = value[i+1] / N, y2 = value[i+1] % N;
            B[x][y] = &A[x2][y2];
        }
    }
    return;
}
