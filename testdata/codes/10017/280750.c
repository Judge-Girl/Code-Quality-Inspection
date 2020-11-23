#include <stdio.h>
#include <stdlib.h>
 
#define MAX_NUMBER_OF_ROUND 50000
 
int main(int argc , char **argv)
{
    int number_of_round;
    int x[2][MAX_NUMBER_OF_ROUND] , y[2][MAX_NUMBER_OF_ROUND];
    int min_distance;
 
    scanf("%d" , &number_of_round);
 
    scanf("%d%d" , &(x[0][0]) , &(y[0][0]));
    scanf("%d%d" , &(x[1][0]) , &(y[1][0]));
    printf("%d\n" , abs(x[0][0] - x[1][0]) + abs(y[0][0] - y[1][0]));
    for (int i = 1 ; i < number_of_round ; i++)
    {
        scanf("%d%d" , &(x[0][i]) , &(y[0][i]));
        min_distance = 2147483647;
        for (int j = 0 ; j < i ; j++)
            if (abs(x[0][i] - x[1][j]) + abs(y[0][i] - y[1][j]) < min_distance)
                min_distance = abs(x[0][i] - x[1][j]) + abs(y[0][i] - y[1][j]);
        printf("%d\n" , min_distance);
 
        scanf("%d%d" , &(x[1][i]) , &(y[1][i]));
        min_distance = 2147483647;
        for (int j = 0 ; j < i + 1 ; j++)
            if (abs(x[1][i] - x[0][j]) + abs(y[1][i] - y[0][j]) < min_distance)
                min_distance = abs(x[1][i] - x[0][j]) + abs(y[1][i] - y[0][j]);
        printf("%d\n" , min_distance);
    }
 
    return 0;
}
