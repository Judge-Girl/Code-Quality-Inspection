#include <stdio.h>
#include <stdlib.h>

int pos[2][50000][2];

int main () {
	int count[2] = {}, currentpos[2];
	int n, manhattan, min, player, rival;
	scanf ("%d", &n);
	scanf ("%d%d", &currentpos[0], &currentpos[1]);
	pos[0][count[0]][0] = currentpos[0];
	pos[0][count[0]++][1] = currentpos[1];
	for (int i = 1; i < 2 * n; i++) {
		scanf ("%d%d", &currentpos[0], &currentpos[1]);
		min = 2147483647;
		player = i % 2;
		rival = (i - 1) % 2;
		pos[player][count[player]][0] = currentpos[0];
		pos[player][count[player]++][1] = currentpos[1];
		for (int i = 0; i < count[rival]; i++) {
			manhattan = abs(pos[rival][i][0] - currentpos[0]) + abs (pos[rival][i][1] - currentpos[1]);
			if (manhattan < min)
				min = manhattan;
		}
		printf ("%d\n", min);
	}
}

