const int *map[1024 * 1024];
int pos[1024][1024];

void constructPointerArray(const int a[1024][1024], const int *b[1024][1024], int N)
{
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j ++){
			map[a[i][j]] = &a[i][j];
			pos[i][j] = a[i][j];
		}
	}
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j ++){
			if(pos[i][j] == N * N - 1)
				b[i][j] = map[0];
			else
				b[i][j] = map[pos[i][j] + 1];
		}
	}
	return;
}

