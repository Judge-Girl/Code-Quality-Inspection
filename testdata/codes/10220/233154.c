#include <stdio.h>
#include "constructPointerArray.h"
#define MAXN 1024
int A[MAXN][MAXN];
int *D[MAXN*MAXN];
const int *B[MAXN][MAXN];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
int i, j, k = 0, temp;
for(i = 0; i < N; i++){
for(j = 0; j < N; j++){
B[i][j] = &A[i][j];
D[A[i][j]] = &A[i][j]; 
}
}
for(i = 0; i < N; i++){
for(j = 0; j < N; j++){
temp = *B[i][j];
if(temp == N * N - 1)
  B[i][j] = D[0];
else
  B[i][j] = D[temp+1];
}
}
return;
} 
