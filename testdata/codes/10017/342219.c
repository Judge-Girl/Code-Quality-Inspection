#include <stdio.h>
#define MAX 50000

typedef struct {
	int x, y;
} Pos;
typedef struct {
	Pos player1[MAX], player2[MAX];
} Game;

int ABS(int x)
{
	return (x > 0 ? x : -x);
}
int ManhattanDistance(const Pos *p1, const Pos *p2)
{
	return ABS(p1->x - p2->x) + ABS(p1->y - p2->y);
}
void Process(Game *game)
{
	int n;
	scanf("%d", &n);
	for (int round = 0; round < n; round++) {
		scanf("%d%d", &(game->player1[round].x), &(game->player1[round].y));
		if (round != 0) {
			int min_distance = ManhattanDistance(&game->player1[round], &game->player2[0]);
			for (int i = 1; i < round; i++) {
				int curr_distance = ManhattanDistance(&game->player1[round], &game->player2[i]);
				if (curr_distance < min_distance)
					min_distance = curr_distance;
			}
			printf("%d\n", min_distance);
		}
		scanf("%d%d", &(game->player2[round].x), &(game->player2[round].y));
		int min_distance = ManhattanDistance(&game->player2[round], &game->player1[0]);
		for (int i = 1; i <= round; i++) {
			int curr_distance = ManhattanDistance(&game->player2[round], &game->player1[i]);
			if (curr_distance < min_distance)
				min_distance = curr_distance;
		}
		printf("%d\n", min_distance);
	}
	return;
}
int main(void)
{
	Game game;
	Process(&game);
	return 0;
}


