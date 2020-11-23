#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int map[50000][2][2] = {}, N, move;

int searchlen(int x, int y, int op){
	int minlen = 1000000000, len;
	for(int i = 0; i < move; i++){
		len = abs(map[i][0][op] - x) + abs(map[i][1][op] - y);
		if(len < minlen)
			minlen = len;
	}
	return minlen;
}

int main(){  
	int N, x, y; 
	int op = 0;
	scanf("%d", &N);
	scanf("%d%d", &x, &y);
	map[0][0][op] = x, map[0][1][op] = y;
	op = !op;
	for(int i = 1; i < 2 * N; i++){
		scanf("%d%d", &x, &y);
		move = (i + 1) / 2;
		map[i / 2][0][op] = x, map[i / 2][1][op] = y;
		op = !op;		
		printf("%d\n", searchlen(x, y, op));
	}
    return 0;
}

