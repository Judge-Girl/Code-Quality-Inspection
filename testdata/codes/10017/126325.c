#include<stdio.h>
int abs(int a,int b){
	return a>b?a-b:b-a;
}
int dis(int a[],int b[]){
	return abs(a[0],b[0])+abs(a[1],b[1]);
}
int min(int a,int b){
	return a>b?b:a;
}
int main(){
	int n;
	scanf("%d",&n);
	int place[n][2];
	int place2[n][2];
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&place[i][0],&place[i][1],&place2[i][0],&place2[i][1]);
		int m=2147483647;
		int m2=2147483647;
	
		for(int j=0;j<i;j++){
			m=min(m,dis(place[i],place2[j]));
			m2=min(m2,dis(place2[i],place[j]));
		}
		m2=min(m2,dis(place2[i],place[i]));
		
		if(i!=0)printf("%d\n%d\n",m,m2);
		else printf("%d\n",m2);
	}
	
	return 0;
}

