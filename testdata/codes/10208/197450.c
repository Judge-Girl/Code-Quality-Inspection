#include <stdio.h>
#include <stdlib.h>

int main() {
	int a,b,c,d,h,nh;
	scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
	nh=(a*b*h)/(a*b-c*d);
	printf("%d\n",nh);
	
	return 0;
}
