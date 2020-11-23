int **C[1024 * 1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	
	int i, j;
	
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			B[i][j] = &A[i][j];
			C[A[i][j]] = &B[i][j];
		}
	}
	
	int *zero;
	zero = *C[0];
	
	for (i = 0; i < N * N - 1; i++){
		*C[i] = *C[i + 1];
	}
	*C[ N * N - 1] = zero;
}
