#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct pos{
    int x;
    int y;
} Pos;

int ABS(int x, int y){
    if(x - y > 0){
        return x - y;
    }
    return y - x;
}

int ManhattanDistance(int x1, int y1, int x2, int y2){
    return ABS(x1, x2) + ABS(y1, y2);
}

int main(void){
    int N;
    scanf("%d", &N);

    int count_1 = 0, count_2 = 0;

    Pos player_1[50000], player_2[50000];
    scanf("%d%d", &player_1[count_1].x, &player_1[count_1].y);
    count_1++;

    for (int i = 0; i < (N * 2) - 1; i++){
        if(i % 2 == 0){
            scanf("%d%d", &player_2[count_2].x, &player_2[count_2].y);
            int min = 2147483647;
            for(int j = 0; j < count_1; j++){
                int distance = ManhattanDistance(player_2[count_2].x, player_2[count_2].y, player_1[j].x, player_1[j].y);
                if(distance < min){
                    min = distance;
                }
            }
            count_2++;
            printf("%d\n", min);
        } else{
            scanf("%d%d", &player_1[count_1].x, &player_1[count_1].y);
            int min = 2147483647;
            for(int j = 0; j < count_2; j++){
                int distance = ManhattanDistance(player_2[j].x, player_2[j].y, player_1[count_1].x, player_1[count_1].y);
                if(distance < min){
                    min = distance;
                }
            }
            count_1++;
            printf("%d\n", min);
        }
    }
    return 0;
}
