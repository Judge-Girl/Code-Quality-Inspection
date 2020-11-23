#include <stdio.h>
#define MAXN 1024
int A[MAXN][MAXN];
const int *B[MAXN][MAXN];
int row[MAXN * MAXN + 2],col[MAXN * MAXN + 2];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
for(int i = 0; i < N;i++)
for(int j = 0; j < N;j++){
B[i][j] = &A[i][j];
}
for(int i = 0; i < N;i++)
for(int j = 0; j < N;j++){
row[A[i][j]] = i;
col[A[i][j]] = j;
}
/* for(int i = 0; i < N;i++)
for(int j = 0; j < N;j++){
printf("%d %d %d\n",A[i][j],row[A[i][j]],col[A[i][j]]);
}*/
for(int i = 0; i < N;i++)
for(int j = 0; j < N;j++){
int temp = *B[i][j];
if(temp != N*N-1) 
B[i][j] = &A[row[temp+1]][col[temp+1]];
else{
B[i][j] = &(A[row[0]][col[0]]);
}
}
}
