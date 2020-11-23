#include <stdio.h>
#include <stdlib.h>

#define MAXSTEP 50000
#define abs(a) (((a) < 0)? -(a):(a))
int distance(int x, int y, int player2[MAXSTEP][2],int n){
	int min = 1<<29;
	int distance;
	for(int i = 0;i < n;i++){
		distance = abs(player2[i][0] - x) + abs(player2[i][1] - y);
		if(distance < min) min = distance;
	}
	return min;
}
int main(){
 	int n;
	scanf("%d",&n);
	int player1[MAXSTEP][2];
	int player2[MAXSTEP][2];
	for(int i = 0;i < n;i++){
		scanf("%d%d",&player1[i][0],&player1[i][1]);
		if(i != 0) printf("%d\n",distance(player1[i][0],player1[i][1],player2,i));
		scanf("%d%d",&player2[i][0],&player2[i][1]);
		printf("%d\n",distance(player2[i][0],player2[i][1],player1,i + 1));
	}
}

