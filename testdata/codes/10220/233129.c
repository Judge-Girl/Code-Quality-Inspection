int *D[1024 * 1024];

void constructPointerArray(int A[1024][1024], const int *B[1024][1024], int N)    {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            D[A[i][j]] = &A[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] + 1 == N * N)   {
                B[i][j] = D[0];
                continue;
            }
            B[i][j] = D[A[i][j] + 1];
        }
    }
}
