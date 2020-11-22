#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, h, c, d;
	int ans;
	scanf("%d %d %d %d %d", &a, &b, &h, &c, &d);
	ans = a*b*h / ((a * b)-(c*d));
	printf("%d", ans);
	system("pause");
	return 0;
}
