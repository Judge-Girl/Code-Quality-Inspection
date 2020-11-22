#include<stdio.h>
main(){
	int a, b, h, c, d;
	int area0, area1, area2;
	int v0, v1;
	int x;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	area0 = a*b;
	area1 = c*d;
	area2 = area0-area1;
	v0 = area0*h;
	x=v0/area2;
	printf("%d", x);
	
}

