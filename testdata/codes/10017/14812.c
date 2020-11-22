#include <stdio.h>
#include <stdlib.h>

int main()
{
	int mini=214748364;
	int n;
	int a[2][50001]={0,0};
	int b[2][50001]={0,0};
	scanf("%d",&n);
	int i;
	for(i=0;i<2*n;++i)
	{
		if (i%2==0)
		{
			int point = i/2;
			scanf("%d%d" ,&a[0][point],&a[1][point]);
		}
		if (i%2==1)
		{
			int point =i/2;
			scanf("%d%d" ,&b[0][point],&b[1][point]);
		}
	}

	for ( i = 1; i < 2*n; ++i)
	{
			if(i%2==0)
			{
			for (int j = 0; j < i/2; ++j)
			{
			 	
				if (abs(a[0][i/2]-b[0][j])+abs(a[1][i/2]-b[1][j])<mini)
				{   
						mini=abs(a[0][i/2]-b[0][j])+abs(a[1][i/2]-b[1][j]);	
				}
			}
			printf("%d\n",mini);
			mini=214748364;
			}
			if(i%2==1)
			{
			for (int j = 0; j <= i/2; ++j)
			{
			 	
				if (abs(a[0][j]-b[0][(i-1)/2])+abs(a[1][j]-b[1][(i-1)/2])<mini)
				{   
					mini=abs(a[0][j]-b[0][(i-1)/2])+abs(a[1][j]-b[1][(i-1)/2]);
				}
			}
			printf("%d\n",mini);
			mini=214748364;
			}
		
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	printf("%d%d\n",a[0][i],a[1][i] );
	// 	printf("%d%d\n",b[0][i],b[1][i] );
	// }
	
	return 0 ;

}
