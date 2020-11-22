#include<stdio.h>
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
        int list[N*N];
        int i,j;
        for(i = 0;i < N;i++){
                for(j = 0;j < N;j++){
                        list[A[i][j]] = N * i + j;
                        /*printf("%d [%d][%d] ",A[i][j],i,j);*/
                }
        }

        for(i = 0;i < N * N;i++){
                B[list[i] / N][list[i] % N] = &A[list[(i+1) % (N*N)] / N][list[(i+1) % (N*N)] % N];
                        /*printf("%d %d\n",list[i] / N,list[i] % N);*/
        }
        return;
}
