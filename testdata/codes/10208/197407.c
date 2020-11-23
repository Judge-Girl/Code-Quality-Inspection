#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, h, c, d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	int tmp = a*b*h;
	int ans = tmp / (a*b - c*d);
	printf("%d", ans);
}
