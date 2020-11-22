#include <stdio.h>
#include <stdlib.h>
short chess[2][50000][2];
int find_small(int num,int side,int x,int y)
{
	int min=1000000;
	for(int i=0;i<num;i++)
	{
		int sum=abs(x-chess[side][i][0])+abs(y-chess[side][i][1]);
		if(sum<min)
			min=sum;
	}
	return min;
}
int main()
{
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		chess[0][i][0]=x;
		chess[0][i][1]=y;
		if (i!=0)
		{
			printf("%d\n",find_small(i,1,x,y));
		}
			
		scanf("%d%d",&x,&y);
		chess[1][i][0]=x;
		chess[1][i][1]=y;
		printf("%d\n",find_small(i+1,0,x,y));
	}
	return 0;
}
