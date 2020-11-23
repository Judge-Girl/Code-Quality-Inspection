int *C[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
  int i, j;
  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++)
        C[A[i][j]] = &(A[i][j]);
  }
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            B[i][j] = C[(A[i][j]+1)%(N*N)];
        }
    }
}

