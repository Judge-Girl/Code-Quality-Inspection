#include <stdio.h>
int main()
{
	int a,b,h,c,d,depth;
	scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
	depth = a*b*h/(a*b-c*d);
	printf("%d",depth);
	return 0;
}

