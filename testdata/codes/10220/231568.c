int graph[1024*1024][2];
void constructPointerArray(const int A[1024][1024],const int *B[1024][1024], int N){
    for( int i = 0; i < N; i++ )
        for( int j = 0; j < N; j++){
            graph[ A[i][j] ][0] = i;
            graph[ A[i][j] ][1] = j;
        }
    for( int i = 0; i < N; i++ )
        for( int j = 0; j < N; j++)
            B[ i ][ j ] = &A[ graph[(A[i][j]+1)%(N*N)][0] ][ graph[(A[i][j]+1)%(N*N)][1] ];
    return;
}
