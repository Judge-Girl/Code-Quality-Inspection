int pos[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){

    for( int i = 0 ; i < N*N ; i++)
        pos[A[i/N][i%N]] = i;

    for( int i = 0 ; i < N*N ; i++){ //i to i+1
        if( i == N*N-1 ) B[pos[i]/N][pos[i]%N] = &A[pos[0]/N][pos[0]%N];
        else B[pos[i]/N][pos[i]%N] = &A[pos[i+1]/N][pos[i+1]%N];
    }

    return;
}
