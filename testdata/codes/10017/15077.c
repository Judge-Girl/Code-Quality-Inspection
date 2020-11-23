#include<stdio.h>
int abs(int x){
	if(x<0)return -x;
	return x;
}
int main(){
	int N,map[2][50010][2],a,b,ink[2]={0},turn=0;
	scanf("%d",&N);
	N=N*2-1;
	scanf("%d%d",&a,&b);
	map[turn][ink[turn]][0]=a;
	map[turn][ink[turn]][1]=b;
	ink[turn]++; 
	turn=1-turn;
	while(N--){
		scanf("%d%d",&a,&b);
		map[turn][ink[turn]][0]=a;
		map[turn][ink[turn]][1]=b;
		int d=2000000000;
		for(int i=0;i<ink[1-turn];i++)if(abs(map[1-turn][i][0]-a)+abs(map[1-turn][i][1]-b)<d)d=abs(map[1-turn][i][0]-a)+abs(map[1-turn][i][1]-b);
		printf("%d\n",d);
		ink[turn]++; 
		turn=1-turn;
	}
	return 0;
}

