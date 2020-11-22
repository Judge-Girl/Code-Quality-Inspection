#include <stdio.h>

int main(){
	int a, b, h, c, d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);

	int vol = a * b * h;
	int dep = vol / (a * b - c * d);
	printf("%d\n", dep);
	return 0;
}
