#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct pos{
    int x;
    int y;
} Pos;

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
                if(abs(player_2[count_2].x - player_1[j].x) + abs(player_2[count_2].y - player_1[j].y) < min){
                    min = abs(player_2[count_2].x - player_1[j].x) + abs(player_2[count_2].y - player_1[j].y);
                }
            }
            count_2++;
            printf("%d\n", min);
        } else{
            scanf("%d%d", &player_1[count_1].x, &player_1[count_1].y);
            int min = 2147483647;
            for(int j = 0; j < count_2; j++){
                if(abs(player_1[count_1].x - player_2[j].x) + abs(player_1[count_1].y - player_2[j].y) < min){
                    min = abs(player_1[count_1].x - player_2[j].x) + abs(player_1[count_1].y - player_2[j].y);
                }
            }
            count_1++;
            printf("%d\n", min);
        }
    }
    return 0;
}
