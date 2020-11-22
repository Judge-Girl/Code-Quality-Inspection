#include <stdio.h>
#include <stdlib.h>
typedef struct{
	short x,y;
}Pos;
int ManDis(Pos a,Pos b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int Search(Pos Data[],int n,Pos Target){
	int dis=65535;
	for(int i=0;i<n;i++){
		int t=ManDis(Data[i],Target);
		if(t<dis)
			dis=t;
	}
	return dis;
}
int main()
{
	int N;
	scanf("%d",&N);
	Pos Dora[50000];
	Pos Sora[50000];
	for(int i=0;i<N;i++){
		Pos p;
		scanf("%d%d",&p.x,&p.y);
		Dora[i]=p;
		if(i)
			printf("%d\n",Search(Sora,i,p));
		scanf("%d%d",&p.x,&p.y);
		Sora[i]=p;
		printf("%d\n",Search(Dora,i+1,p));
	}
	return 0;
} 

