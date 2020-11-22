int array[1024*1024][2];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
	int i , j;
	for(i = 0 ; i < N ; i ++)
		for(j = 0 ; j < N ; j++)
		{
			array[A[i][j]][0] = i;
			array[A[i][j]][1] = j;
		}
	for(i = 0 ; i < N*N-1 ; i++)
	{
		int r = array[i][0];
		int c = array[i][1];
		int r1 = array[i+1][0];
		int c1 = array[i+1][1];
		B[r][c] = &A[r1][c1];
	}
	int r = array[N*N-1][0];
	int c = array[N*N-1][1];
	int r1 = array[0][0];
	int c1 = array[0][1];
	B[r][c] = &A[r1][c1];
}

