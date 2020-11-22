#include <stdio.h>
main()
{
	int a, b, c, d, h;
	int x;
	scanf("%d%d%d%d%d", &a,&b,&h,&c,&d);
	printf("%d", c * d * h / (a * b - c * d) + h );
} 

