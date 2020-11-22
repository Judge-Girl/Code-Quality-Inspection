#include <stdio.h>
typedef struct{
	short x,y;
}Pos;
int ManDis(Pos a,Pos b){
	return (a.x>b.x?a.x-b.x:b.x-a.x)+(a.y>b.y?a.y-b.y:b.y-a.y);
}
int Search(Pos Data[],int pt_Data,Pos Target){
	int dis=65535;
	int t;
	for(int i=0;i<pt_Data;i++){
		if((t=ManDis(Data[i],Target))<dis)
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
	int pt_Dora=0,pt_Sora=0;
	for(int i=0;i<N;i++){
		Pos p;
		scanf("%d%d",&p.x,&p.y);
		Dora[pt_Dora++]=p;
		if(i!=0)
			printf("%d\n",Search(Sora,pt_Sora,p));
		scanf("%d%d",&p.x,&p.y);
		Sora[pt_Sora++]=p;
		printf("%d\n",Search(Dora,pt_Dora,p));
	}
	return 0;
} 

