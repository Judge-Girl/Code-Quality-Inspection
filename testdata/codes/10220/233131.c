int *n1[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
        int i,j,n=0,k,l;
//      int n1[N*N];
#ifdef DEBUG
        printf("N*N-1=%d\n",N*N-1);
#endif
        for ( i=0; i<N; i++){
                for ( j=0; j<N; j++){
				
                	n1[A[i][j]]=&(A[i][j]);

                }
        }
        int tmp=0,r,c;

	for ( i=0; i<N; i++){
		for ( j=0; j<N; j++){
			B[i][j]=n1[(A[i][j]+1+N*N)%(N*N)];

		}
	}

        return ;
}

