#include <stdio.h>

int new_arr[1024*1024];

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			new_arr[A[i][j]] = i*N+j;
		}
	}
	for(int i = 0; i < N*N-1; i++){
		B[new_arr[i] / N][new_arr[i] % N] = &A[new_arr[i+1]/N][new_arr[i+1]%N];
	}
	B[new_arr[N*N-1] / N][new_arr[N*N-1] % N] = &A[new_arr[0] / N][new_arr[0] % N];
}
/*
int A[MAXN][MAXN];
const int *B[MAXN][MAXN];
#define MAXN 1024
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
