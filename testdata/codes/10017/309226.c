#include <stdio.h>
#include <math.h>

int main()
{
	int n;

	scanf("%d", &n);

	int a[50000][2];
	int b[50000][2];

	int i, j;

	int min_length;

	int first = 1;

	for (i = 0; i < n; i++) 
	{
		scanf("%d %d", &a[i][0], &a[i][1]);
		min_length = 100000;
		for (j = 0; j < i; j++)
		{
			if (abs(a[i][0] - b[j][0]) + abs(a[i][1] - b[j][1]) < min_length) 
			{
				min_length = abs(a[i][0] - b[j][0]) + abs(a[i][1] - b[j][1]);
			
			
			
			}



		}
		if (first == 0) 
		{
			printf("%d\n", min_length);
		
		}
		first = 0;

		scanf("%d %d", &b[i][0], &b[i][1]);
		min_length = 100000;
		for (j = 0; j < i + 1; j++) 
		{
			if (abs(a[j][0] - b[i][0]) + abs(a[j][1] - b[i][1]) < min_length)
			{
				min_length = abs(a[j][0] - b[i][0]) + abs(a[j][1] - b[i][1]);



			}



		}
		printf("%d\n", min_length);
	}

}
