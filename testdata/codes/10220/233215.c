#include <stdio.h>
#define MAXN 1024
 
int graph[1024*1024][2];
 
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
    int i,j;
    for(i = 0; i < N; i ++)
        for(j = 0; j < N; j ++)
        {
            graph[A[i][j]][0] = i;
            graph[A[i][j]][1] = j;
        }
    for(i = 0; i < N*N; i ++)
    {
        B[graph[i][0]][graph[i][1]] = &A[graph[(i + 1) % (N*N)][0]][graph[(i + 1) % (N*N)][1]];
    }
}
