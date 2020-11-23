#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int abs(int k){
    if (k>=0)
        return k;
    return -k;
}
int mandist(int ax,int ay,int bx,int by){
    return abs(ax-bx)+abs(ay-by);
}

void printdist(int kx[],int ky[],int x,int y,int cnt){
    int mindist=100000000;
    for(int i=0;i<cnt;i++){
        if( mandist(kx[i],ky[i],x,y) < mindist )
            mindist= mandist(kx[i],ky[i],x,y);
    }
    printf("%d\n",mindist);
}

int main(){
    int n;
    scanf("%d",&n);
    int ax[50001]={0},ay[50001]={0},bx[50001]={0},by[50001]={0};
    for(int i=0;i<2*n;i++){
        if( i%2==0){
            scanf("%d %d ",&ax[i/2],&ay[i/2]);
            if(i!=0)
              printdist( bx, by, ax[i/2], ay[i/2],i/2);
        }
        else{
            scanf("%d %d ",&bx[i/2],&by[i/2]);
            printdist( ax, ay, bx[i/2], by[i/2],i/2+1);
        }
    }
    return 0;
}
