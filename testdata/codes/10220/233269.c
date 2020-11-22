#include<stdio.h>
int *addr[1048576];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
    
    int i, j;
    
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            addr[A[i][j]] = &A[i][j];

        }
    }
    
    for(i = 0;i < N; i++){
        for(j = 0;j < N; j++){
            if(A[i][j] != N*N-1)
                B[i][j] = addr[A[i][j] + 1];
            else
                B[i][j] = addr[0];
        }
    }
    return;
}

