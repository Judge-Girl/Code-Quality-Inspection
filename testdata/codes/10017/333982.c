#include <stdio.h>
#include <stdlib.h>

#define Player1 1
#define Player2 -1

int player1[500000][2], player2[500000][2], x, y;

void compare(int player[][2], int num){
	int max = 100000, buf;
	for(int cnt = 0; cnt < num; cnt++){
		buf = abs(player[cnt][0] - x) + abs(player[cnt][1] - y);
		if(max > buf)
			max = buf;
	}
	printf("%d\n", max);
	return;
}

int main(){
	int stepNum;
	scanf("%d", &stepNum);
	int step = 1, player = -1;
	scanf("%d%d", &x, &y);
	player1[0][0] = x, player1[0][1] = y;
	while(step < stepNum){
		scanf("%d%d", &x, &y);
		player2[step - 1][0] = x, player2[step - 1][1] = y;
		compare(player1, step);
		scanf("%d%d", &x, &y);
		player1[step][0] = x, player1[step][1] = y;
		compare(player2, step);
		step++;
	}
	scanf("%d%d", &x, &y);
	player2[step][0] = x, player2[step][1] = y;
	compare(player1, step + 1);
	return 0;
}

