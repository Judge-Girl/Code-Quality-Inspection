#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int a, b, h, c, d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	//printf("%d %d %d %d %d\n", a, b, h, c, d);
	//int ans = 0;
	//a*b*(ans) = c*d*(ans+h)
	//(a*b-c*d)*ans = c*d*h
	printf("%d", h+c*d*h/(a*b-c*d));
	return 0;
} 

