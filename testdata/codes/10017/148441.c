#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x;
    int y;
} Point;
int main()
{
    int n ; scanf("%d",&n);
    int cnt = 0;
    n--;
    int min;
    Point point1[50000];
    Point point2[50000];
    scanf("%d%d%d%d",&point1[cnt].x,&point1[cnt].y,&point2[cnt].x,&point2[cnt].y);
    cnt++;
    printf("%d\n",abs(point2[0].x - point1[0].x) + abs(point2[0].y-point1[0].y));
    while(n--){
        scanf("%d%d%d%d",&point1[cnt].x,&point1[cnt].y,&point2[cnt].x,&point2[cnt].y);
        min = 1000000000;
        for(int i = 0 ; i < cnt ; i++){
            if( ( abs(point1[cnt].x - point2[i].x) + abs(point1[cnt].y - point2[i].y) ) < min ){
                min = abs(point1[cnt].x - point2[i].x) + abs(point1[cnt].y - point2[i].y) ;
            }
            
        }
        printf("%d\n",min);
        min = 1000000000;
        for(int i = 0 ; i < cnt+1 ; i++){
                if( ( abs(point2[cnt].x - point1[i].x) + abs(point2[cnt].y - point1[i].y) ) < min ){
                min = abs(point2[cnt].x - point1[i].x) + abs(point2[cnt].y - point1[i].y) ;
            }
        }
        printf("%d\n",min);
        cnt++;
    }
}

