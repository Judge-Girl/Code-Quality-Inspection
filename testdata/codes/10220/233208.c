#include "constructPointerArray.h"
#include<stdio.h>
int num[1024*1024][2];
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
for(int i = 0; i < N; i++)
for(int j = 0; j < N; j++){
num[A[i][j]][0] = i;
num[A[i][j]][1] = j;
}
for(int i = 0; i < N*N; i++){
if(i != N*N-1){
B[num[i][0]][num[i][1]] = &A[num[i+1][0]][num[i+1][1]];
}
else
B[num[i][0]][num[i][1]] = &A[num[0][0]][num[0][1]];
}
}
