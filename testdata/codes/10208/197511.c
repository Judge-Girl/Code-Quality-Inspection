#include<stdio.h>

int main()
{
	int a,b,h,c,d,hh; 
	
	scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
	hh=(a*b*h)/(a*b-c*d);
	printf("%d\n",hh);
	return 0;
}
