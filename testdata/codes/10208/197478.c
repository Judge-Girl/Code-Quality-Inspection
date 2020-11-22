#include <stdio.h>

int main(){
	int a, b, h, c, d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	int waterorivol=a*b*h;
	int newarea=(a*b)-(c*d);
	int hh=waterorivol/newarea;
	printf("%d", hh);
	return 0;
}
