#include <stdio.h>
main()
{
	int a,b,c,d,h,ans;
	scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
	ans = a * b * h / (a * b - c * d);
	printf("%d",ans);
	return 0;
} 
