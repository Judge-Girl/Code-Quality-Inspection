#include<stdio.h>
int main()
{
	int a, b, h, c, d, f;
	scanf("%d\n%d\n%d\n%d\n%d", &a, &b, &h, &c, &d);
	f=((a*b*h)/((a*b)-(c*d)));
	printf("%d", f);
	return 0;
}

