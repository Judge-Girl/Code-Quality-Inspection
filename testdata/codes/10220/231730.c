#define MAXN 1024
int *p[MAXN][MAXN];
int num[MAXN*MAXN][2];
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			num[A[i][j]][0] = i;
			num[A[i][j]][1] = j;
		}
	}
	for(i = 0; i < N*N - 1; i++){
		B[num[i][0]][num[i][1]] = &A[num[i+1][0]][num[i+1][1]];
	}
	B[num[N*N-1][0]][num[N*N-1][1]] = &A[num[0][0]][num[0][1]];
	
}

