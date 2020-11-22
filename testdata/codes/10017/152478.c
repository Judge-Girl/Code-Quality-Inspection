#include <stdio.h>
#include <stdlib.h>
int map[100000][2];
int main()
{
	int N, i, j;
	scanf("%d%d%d", &N, &map[0][0], &map[0][1]);
	for (i = 1; i < 2 * N; i ++){
		int min = 0x7fffffff, dist;
		scanf("%d%d", &map[i][0], &map[i][1]);
		for (j = !(i & 1); j < i; j += 2){
			dist = abs(map[i][0] - map[j][0]) + abs(map[i][1] - map[j][1]);
			min = (min > dist)? dist: min;
		}
		printf("%d\n", min);
	}
	return 0;
}

