#include <stdio.h>
#include <stdlib.h>
#define MAX 54787
#define MIN(a,b) (a<b)?a:b
typedef struct{
    int x, y;
}point;
point Steph[MAX], Sora[MAX];
int distance(point A, point B)
{
    return (abs(A.x - B.x)) + (abs(A.y - B.y));
}
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d", &Sora[i].x, &Sora[i].y);
        int min = 0x3f3f3f3f;
        for(int j=0;j<i;j++)
            min = MIN(min, distance(Sora[i], Steph[j]));
        if(i != 0)
            printf("%d\n", min);
        min = 0x3f3f3f3f;
        scanf("%d %d", &Steph[i].x, &Steph[i].y);
        for(int j=0;j<=i;j++)
            min = MIN(min, distance(Steph[i], Sora[j]));
        printf("%d\n", min);
    }
}
