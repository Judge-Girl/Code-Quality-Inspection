#include<stdio.h>
int main()
{
	int a, b, h, c, d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	int h2 = (a * b * h) / (a * b - c * d);
	printf("%d", h2);
	
	
 } 

