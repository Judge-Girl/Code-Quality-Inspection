#include <stdio.h>
main(){
	int a, b, h, c, d, x;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	x = (c*d*h)/(a*b-c*d);
	printf("%d",h+x);
	return 0;
}

