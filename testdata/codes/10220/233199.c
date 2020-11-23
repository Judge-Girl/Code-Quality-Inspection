#define MAXN 1024

int arrD[1024*1024][2], *ptr[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N) {
    int target = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arrD[A[i][j]][0] = i;
            arrD[A[i][j]][1] = j;
            ptr[A[i][j]] = &A[i][j];
        }
    }
    #ifdef DEBUG
    for (int i = 0; i < N*N; i++) {
        printf("%d %d\n", arrD[i][0], arrD[i][1]);
    }
    #endif
    target = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (target == N*N - 1) {
                B[arrD[target][0]][arrD[target][1]] = ptr[0];
                break;
            }
            B[arrD[target][0]][arrD[target][1]] = ptr[target + 1];
            target++;
        }
    }
}
