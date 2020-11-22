#include<stdio.h>
int tmp[1048577];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tmp[A[i][j]]=i*N+j;
        }
    }
    for(int i=0; i<N*N-1; i++){
        B[tmp[i]/N][tmp[i]%N]=&A[tmp[i+1]/N][tmp[i+1]%N];
    }
    B[tmp[N*N-1]/N][tmp[N*N-1]%N]=&A[tmp[0]/N][tmp[0]%N];
}
