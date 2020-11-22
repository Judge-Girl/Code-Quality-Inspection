#include <stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	f=(a*b*c)/(a*b-e*d);
	printf("%d\n",f);
	
	return 0;

}


