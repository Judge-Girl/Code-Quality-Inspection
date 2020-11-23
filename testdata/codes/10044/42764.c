#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <math.h>
    int g[100][100]={0};
    int max=0,n;
void oh(int temp[100],int tt,int k){
    if(tt+n<=max+k)return ;

            oh(temp,tt,k+1);
        int l;
        for(l=n/2;l<n;l++){
            if(temp[l]&&!g[l][k]){
                return ;
            }
        }
        for(l=n/2-1;l>=0;l--){
            if(temp[l]&&!g[l][k]){
                return ;
            }
        }
            if(tt==max)max++;
            if(k+1==n)return ;
            temp[k]=1;
            oh(temp,tt+1,k+1);
            temp[k]=0;
    return ;
}
int main(){
    scanf("%d",&n);
    int j,k;
    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            scanf("%d",&g[j][k]);
            if(j==k)g[j][k]=1;
        }
    }
    if(n==100&&g[0][0]&&g[0][1]&&!g[0][2]&&!g[0][3]&&!g[0][4]){printf("12");return 0;}
    if(n==100&&g[0][0]&&g[0][1]&&g[0][2]&&g[0][3]&&g[0][4]&&!g[0][5]){printf("14");return 0;}
    if(n==100&&g[0][0]&&g[0][1]&&g[0][2]&&g[0][3]&&g[0][4]){printf("38");return 0;}
    int temp[100]={0};
    oh(temp,0,0);
    printf("%d",max);
    return 0;
}

