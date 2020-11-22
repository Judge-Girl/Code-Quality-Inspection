#include<stdio.h>
main()
{
	int a, b, c, h, d, ans;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&h);
	scanf("%d",&c);
	scanf("%d",&d);
	ans = (a * b * h) / ((a * b) - (c * d));
	printf("%d\n",ans);
 } 

