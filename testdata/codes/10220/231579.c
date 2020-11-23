#define MAXN 1024
int* position[MAXN * MAXN];
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			position[A[i][j]] = &A[i][j];

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(A[i][j] == N * N - 1)
				B[i][j] = position[0];
			else
				B[i][j] = position[A[i][j] + 1];
		}
	}
}
