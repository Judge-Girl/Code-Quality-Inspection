#include<stdio.h>
#include<stdlib.h>
#define MAX 50000
int a[2][MAX], b[2][MAX];
int main(void)
{
	int n;
	scanf("%d", &n);

	scanf("%d%d", &a[0][0], &a[1][0]);
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			int absb = 65540;
			scanf("%d%d", &b[0][0], &b[1][0]);
			for(int j = 0; j <= i; j++)
			{
				int l = abs(b[0][0] - a[0][j]) + abs(b[1][0] - a[1][j]);
				if ( l < absb)
					absb = l; 
			}
			printf("%d\n", absb);
		}

		else
		{
			int absa = 65540;
			scanf("%d%d", &a[0][i], &a[1][i]);
			for(int j = 0; j < i; j++)
			{
				int l = abs(a[0][i] - b[0][j]) + abs(a[1][i] - b[1][j]);
				if (l < absa)
					absa = l; 
			}

			int absb = 65540;
			scanf("%d%d", &b[0][i], &b[1][i]);
			for(int j = 0; j <= i; j++)
			{
				int l = abs(b[0][i] - a[0][j]) + abs(b[1][i] - a[1][j]);
				if ( l < absb)
					absb = l; 
			}

			printf("%d\n%d\n", absa, absb);

		}
	}
	return 0;
}
