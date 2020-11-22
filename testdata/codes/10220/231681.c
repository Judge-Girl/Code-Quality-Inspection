void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	int array[N * N];
	for(int r = 0; r < N; r++){
		for(int c = 0; c < N; c++){
			int k = A[r][c];
			array[k] = r * N + c;
		}
	}

	for(int r = 0; r < N; r++){
		for(int c = 0; c < N; c++){
			int k = (A[r][c] + 1) % (N * N);
			B[r][c] = &A[array[k] / N][array[k] % N];
		}
	}
}
