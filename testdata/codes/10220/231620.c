#define MAXN 1024
int d[1100000][2];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    int nowx,nowy;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N ; j++){
            d[A[i][j]][0] = i;
            d[A[i][j]][1] = j;
        }
    }
    nowx = d[0][0];
    nowy = d[0][1];
    for(int i = 0; i < N*N-1; i++){
        B[nowx][nowy] = &A[d[i+1][0]][d[i+1][1]];
        nowx = d[i+1][0];
        nowy = d[i+1][1];
    }
    B[d[N*N-1][0]][d[N*N-1][1]] = &A[d[0][0]][d[0][1]];
}

