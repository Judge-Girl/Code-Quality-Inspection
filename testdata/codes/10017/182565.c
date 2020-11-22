#include<stdio.h>
#include<stdio.h>
#include<limits.h>
#include<math.h>

short point[2][50000][2] = {};
int n;
short x,y;
int Manhattan_dist(short px,short qx,short py,short qy){
    return abs(px - qx) + abs(py - qy);
}

int min_dist(int t){
    int min = INT_MAX,q = t?0:1;
    int i;
    for(i=0;i<n+t;i++){
        int d = Manhattan_dist(point[q][i][0],x,point[q][i][1],y);
        if(min > d)
            min = d;
    }
    return min;
}

int main(){
    int i;
    int N;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d",&x,&y);
        point[0][n][0] = x,point[0][n][1] = y;
        if(n > 0) printf("%d\n",min_dist(0));
        scanf("%d%d",&x,&y);
        point[1][n][0] = x,point[1][n][1] = y;
        printf("%d\n",min_dist(1));
        n++;
    }
}
