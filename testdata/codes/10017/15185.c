#include<stdio.h>
int abs(int a){
    if(a<0)
        a=-a;
    return a;
}
int main()
{
    int player1[50000][2] ,player2[50000][2];
    int n;
    int i ,j;
    int min_dis;
    int dis;
    scanf("%d" ,&n);
    for(i=0 ;i<n ;i++){
        scanf("%d %d" ,&player1[i][0] ,&player1[i][1]);
        if(i){
            min_dis=0;
            for(j=0 ;j<i ;j++){
                dis=abs(player1[i][0]-player2[j][0])+abs(player1[i][1]-player2[j][1]);
                if(!min_dis)
                    min_dis=dis;
                if(dis<min_dis)
                    min_dis=dis;
            }
            printf("%d\n" ,min_dis);
        }
        min_dis=0;
        scanf("%d %d" ,&player2[i][0] ,&player2[i][1]);
        for(j=0 ;j<=i ;j++){
            dis=abs(player2[i][0]-player1[j][0])+abs(player2[i][1]-player1[j][1]);
            if(!min_dis)
                min_dis=dis;
            if(dis<min_dis)
                min_dis=dis;
        }
        printf("%d\n" ,min_dis);
    }
    return 0;
}

