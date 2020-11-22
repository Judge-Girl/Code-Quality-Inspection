#include<stdio.h>
#include<stdlib.h>
#define inf 2147483645
#define min(a,b) (a<b?a:b)
typedef struct{
	int x,y;
}crood;
crood A[2][50001];
int dis(crood a,crood b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		A[0][i]=(crood){x,y};
		int ans=inf;
		for(int j=0;j<i;j++){
			ans=min(ans,dis(A[1][j],A[0][i]));
		}
		if(ans!=inf)
		printf("%d\n",ans);
		scanf("%d%d",&x,&y);
		A[1][i]=(crood){x,y};
		ans=inf;
		for(int j=0;j<=i;j++){
			ans=min(ans,dis(A[0][j],A[1][i]));
		}
		printf("%d\n",ans);
	}
	return 0;
}

