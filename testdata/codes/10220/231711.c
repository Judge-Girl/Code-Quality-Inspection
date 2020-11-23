#define MAXN 1024
int* save[MAXN*MAXN];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int p=A[i][j];
			save[p]=&(A[i][j]);
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i][j]==N*N-1){
				B[i][j]=save[0];
			}
			else
				B[i][j]=save[A[i][j]+1];
		}
	}
}
