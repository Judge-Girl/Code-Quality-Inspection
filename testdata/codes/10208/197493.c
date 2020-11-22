#include <stdio.h>

int main()
{
	int a,b,h,c,d;
	scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
	printf("%d",h + (c * d * h) / (a * b - c * d));
	return 0;
	
 } 
