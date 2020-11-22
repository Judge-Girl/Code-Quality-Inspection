#include<stdio.h>
main()
{
	int a,b,h,c,d;
	scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);

	int v,area,depth;
	v = a*b*h;
	area = a*b - c*d;
	depth = v / area;

	printf("%d\n",depth);

	return 0 ; 
}
