#include <stdio.h>
#ifndef CONSTRUCT
#define CONSTRUCT
#define MAXN 1024
int *add[1024*1024];
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			add[A[i][j]]=&A[i][j];
			//printf("%d\n",*add[A[i][j]]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(A[i][j]<N*N-1){
				B[i][j]=add[A[i][j]+1];
			}else if(A[i][j]==N*N-1){
				B[i][j]=add[0];
			}
		}
	}
	
}
#endif
/*int A[MAXN][MAXN];
const int *B[MAXN][MAXN];
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    constructPointerArray(A, B, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d%c ", *B[i][j], j == N - 1 ? '\n' : ' ');
        }
    }
    return 0;
}*/

