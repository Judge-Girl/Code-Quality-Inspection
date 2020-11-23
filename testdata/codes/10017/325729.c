#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Row Column
int first[50000][2];
int second[50000][2];
int main(void){
    int N;
    scanf("%d", &N);
    int first_count = 0;
    int second_count = 0;
    int row, column;
    bool start = true;
    for (int i = 0; i < N; i++){
        scanf("%d%d", &row, &column);
        first[first_count][0] = row;
        first[first_count][1] = column;
        first_count++;
        if (start)
            start = false;
        else{
            int min = __INT32_MAX__;
            for (int j = 0; j < second_count; j++){
                int distance = abs(row - second[j][0]) + abs(column - second[j][1]);
                min = (distance < min) ? distance : min;
            }
            printf("%d\n", min);
        }


        scanf("%d%d", &row, &column);
        second[second_count][0] = row;
        second[second_count][1] = column;
        second_count++;
        int min = __INT32_MAX__;
        for (int j = 0; j < first_count; j++){
            int distance = abs(row - first[j][0]) + abs(column - first[j][1]);
            min = (distance < min) ? distance : min;
        }
        printf("%d\n", min);
    }
}
