typedef struct cell{
	int row, col;
}Cell;
Cell pos[1024*1024];
void get_pos(const int A[1024][1024], int N){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			pos[A[i][j]].row = i;
			pos[A[i][j]].col = j;
		}
	}
}
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	get_pos(A,N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int next;
			if(A[i][j]==N*N-1)
				next = 0;
			else
				next = A[i][j]+1;
			B[i][j] = &A[pos[next].row][pos[next].col];
		}
	}
}
