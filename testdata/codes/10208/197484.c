#include <stdio.h>
int main () {
	int a,b,h,c,d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	int volume = a*b*h;
	int area = (a*b)-(c*d);
	printf("%d\n", volume/area);
	return 0;
}
