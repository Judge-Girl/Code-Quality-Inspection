int x[1024*1024],y[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	int a,b,c;
	
	for(a=0;a<N;a++){
		for(b=0;b<N;b++){
			int value=A[a][b];
				x[value]=a;			
				y[value]=b;
		}
	}
	for(a=0;a<N;a++){
		for(b=0;b<N;b++){
			if(A[a][b]==N*N-1) B[a][b]=&A[x[0]][y[0]];
			else B[a][b]=&A[x[A[a][b]+1]][y[A[a][b]+1]];
		}
	}
}
