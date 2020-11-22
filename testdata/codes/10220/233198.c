#define MAXN 1024
int *buffer[MAXN*MAXN]; 
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
	int i,j;
	for(i=0;i<N;i++) 
		for(j=0;j<N;j++) 
			buffer[A[i][j]] = &(A[i][j]);

	for(i=0;i<N;i++) 
		for(j=0;j<N;j++) 
			B[i][j] = A[i][j]==N*N-1? buffer[0] : buffer[(A[i][j])+1]; 
return;}

