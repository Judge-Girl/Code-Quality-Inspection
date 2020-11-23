#include<stdio.h>
main()
{
	int a,b,h,c,d,hight;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&h);
	scanf("%d",&c);
	scanf("%d",&d);
	hight=a*b*h/(a*b-c*d);
	printf("%d\n",hight);
}
