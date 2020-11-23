#include <stdio.h>
#include <string.h>

int dp[105][105] = {};
int mx = 0;
int g[105][105] = {};
int Dp[105] = {};

void search(int n,int np,int dep){
    if(np == 0){
        if(dep > mx)mx = dep;
        return;
    }
    if(dep + np < mx)return;
    for(int i=0;i<np;i++){
        int k = dp[dep][i],cnt = 0;
        if(dep + n - k < mx)return;
        if(dep + Dp[k] < mx)return;
        for(int j=i+1;j<np;j++){
            int l = dp[dep][j];
            if(g[k][l])dp[dep+1][cnt++] = l;
        }
        search(n,cnt,dep+1);
    }
}

int clique(int n){
    for(int i=n-1;i>=0;i--){
        int cnt = 0;
        for(int j=i+1;j<n;j++){
            if(g[i][j])dp[1][cnt++] = j;
        }
        search(n,cnt,1);
        Dp[i] = mx;
    }
    return mx;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    int ans = clique(n);
    printf("%d\n",mx);
    return 0;
}
