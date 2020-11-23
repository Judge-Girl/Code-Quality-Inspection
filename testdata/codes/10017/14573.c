#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x[2][40000] = {{0}}, y[2][40000] = {{0}};
	int stp = 0;
	int n;
	scanf("%d", &n);
	scanf("%d%d", &x[0][stp], &y[0][stp]);
	int dstnz;
	while(n--)
	{
		int shrt = 1000000;
		scanf("%d%d", &x[1][stp], &y[1][stp]);
		for(int i = 0;i <= stp;i++)
		{
			dstnz = abs(x[0][i] - x[1][stp]) + abs(y[0][i] - y[1][stp]);
			if(shrt > dstnz)
				shrt = dstnz;
		}
		printf("%d\n", shrt);
		
		stp++;
		if(n == 0)
			break;
		
		shrt = 1000000;
		scanf("%d%d", &x[0][stp], &y[0][stp]);
		for(int i = 0;i < stp;i++)
		{
			dstnz = abs(x[1][i] - x[0][stp]) + abs(y[1][i] - y[0][stp]);
			if(shrt > dstnz)
				shrt = dstnz;
		}
		printf("%d\n", shrt);
	}
	return 0;
}

