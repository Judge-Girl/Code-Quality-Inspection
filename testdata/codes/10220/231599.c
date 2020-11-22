int arr[1048576][2];

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ; j++){
			arr[A[i][j]][0] = i;
			arr[A[i][j]][1] = j;
		}
	for(int i = 0 ; i < N * N - 1 ; i++)
		B[arr[i][0]][arr[i][1]] = &A[arr[i + 1][0]][arr[i + 1][1]];
	B[arr[N * N - 1][0]][arr[N * N - 1][1]] = &A[arr[0][0]][arr[0][1]];
}

