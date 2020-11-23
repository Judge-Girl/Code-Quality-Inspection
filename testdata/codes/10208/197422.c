#include <stdio.h>

int main() {
	int a, b, h, c, d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	int vol = a*b*h;
	int new_h = vol / ( a*b - c*d );
	printf("%d",new_h);
	return 0;
}


