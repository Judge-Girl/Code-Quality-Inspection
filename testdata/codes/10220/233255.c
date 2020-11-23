#include <stdio.h>
#define MAXN 1024
int A[MAXN][MAXN];
const int *B[MAXN][MAXN];
    int r[MAXN * MAXN];
    int c[MAXN * MAXN];
 
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    int i, j;
 
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            B[i][j]=&A[i][j];
        }
    }
 
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            r[A[i][j]]=i;
            c[A[i][j]]=j;
        }
    }
 
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            int tem = *B[i][j];
                if(tem != N*N-1){
                    B[i][j] = &A[r[tem+1]][c[tem+1]];
                }
                else{
                    B[i][j] = &(A[r[0]][c[0]]);
                }
        }
    }
 
    /*
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d %d %d\n", row[i][j], A[i][j]=j);
        }
    }*/
 
}
