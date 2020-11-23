int *D[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	int s, p;
	for(s=0; s<N; s++){
		for(p=0; p<N; p++){
			D[A[s][p]]=&A[s][p];
		}
	}
	for(s=0; s<N; s++){
		for(p=0; p<N; p++){
			if(A[s][p]==N*N-1){
				B[s][p]=D[0];
			}
			else{
				B[s][p]=D[A[s][p]+1];
			}
		}
	}
}

