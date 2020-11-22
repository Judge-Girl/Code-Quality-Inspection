int row_number[1024*1024],col_number[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	int i,j;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++){
			row_number[A[i][j]] = i;
			col_number[A[i][j]] = j;
		}
	for(i = 0 ; i < N*N-1; i++)
		B[row_number[i]][col_number[i]] = &A[row_number[i+1]][col_number[i+1]];
	B[row_number[N*N-1]][col_number[N*N-1]] = &A[row_number[0]][col_number[0]];
}
