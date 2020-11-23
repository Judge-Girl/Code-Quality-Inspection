
#define MAXN 1024
const int *c[1100000];


void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++)
			c[A[i][j]]=&A[i][j];
	}
	int k;
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++){
			k=A[i][j];
			if(k!=N*N-1)
				B[i][j]=c[k+1];
			else
				B[i][j]=c[0];
		}
	}
}
