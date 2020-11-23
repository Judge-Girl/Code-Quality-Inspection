int *buf[1024*1024];
void constructPointerArray(const int A[][1024], const int *B[][1024],int N){
    int i,j;
    for(i = 0;i<N;i++){
        for(j = 0;j<N;j++){
            buf[A[i][j]] = &(A[i][j]);
        }
    }
    for(i = 0;i<N;i++){
        for(j = 0;j<N;j++){
            if(A[i][j] == N*N-1){
                B[i][j] = buf[0];
            }
            else{
                B[i][j] = buf[A[i][j]+1];
            }
        }
    }
}

