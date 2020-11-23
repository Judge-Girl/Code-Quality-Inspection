#include <stdio.h>

int main(void) {
	int a,b,h,c,d;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &h);
	scanf("%d", &c);
	scanf("%d", &d);
	printf("%d\n", (a*b*h)/(a*b-c*d));
	return 0;
}
