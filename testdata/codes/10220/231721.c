const int* list[1024][1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int temp = A[i][j];
			list[temp/N][temp%N] = &A[i][j];
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int temp = A[i][j];
			if(temp == N*N - 1) B[i][j] = list[0][0];
			else B[i][j] = list[(temp+1)/N][(temp+1)%N];
		}
	}
}
