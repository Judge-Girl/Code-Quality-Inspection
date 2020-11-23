#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define size 50000

typedef struct game{
  int x;
  int y;
}Game;

int findmindis1(Game player1[size], Game player2[size], int turn, int min_dis)
{
  for (int j = 0; j < turn; j++){
      int temp = abs(player1[turn].x - player2[j].x)
	+ abs(player1[turn].y - player2[j].y);
      if (min_dis > temp)
	min_dis = temp; 
    }
  return min_dis;
}

int findmindis2(Game player1[size], Game player2[size], int turn, int min_dis)
{
  for (int j = 0; j <= turn; j++){
      int temp = abs(player2[turn].x - player1[j].x)
	+ abs(player2[turn].y - player1[j].y);
      if (min_dis > temp)
	min_dis = temp; 
    }
  return min_dis;
}

int main()
{
  int turn;
  Game player1[size], player2[size]; 
  scanf("%d", &turn);
  for (int i = 0; i < turn; i++){
    int min_dis;
    scanf("%d%d", &player1[i].x, &player1[i].y);
    min_dis = findmindis1(player1, player2, i, INT_MAX);
    if (i != 0)
      printf("%d\n", min_dis);
    scanf("%d%d", &player2[i].x, &player2[i].y);
    min_dis = findmindis2(player1, player2, i, INT_MAX);
    printf("%d\n", min_dis);
  }
  return 0;
}

