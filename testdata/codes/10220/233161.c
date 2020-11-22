int ci[1050000], cj[1050000];
int pi[1050000], pj[1050000];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
                if( A[i][j] == 0 ){
                    ci[N*N-1] = i;
                    cj[N*N-1] = j;
                    pi[0] = i;
                    pj[0] = j;
                }
                else{
                    ci[A[i][j]-1] = i;
                    cj[A[i][j]-1] = j;
                    pi[A[i][j]] = i;
                    pj[A[i][j]] = j;
                }
            }
        }
    for(i = 0; i < N*N; i++) B[pi[i]][pj[i]] = &A[ci[i]][cj[i]];

}

