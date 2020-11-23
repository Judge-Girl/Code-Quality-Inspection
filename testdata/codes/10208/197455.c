#include <stdio.h>
int main () {
	int a, b, h, c, d, Ans;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	Ans=(a*b*h)/((a*b)-(c*d));
	printf("%d",Ans);
	return 0;
}

