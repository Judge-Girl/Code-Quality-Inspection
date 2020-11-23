#include <stdio.h>
int main() 
{
	int a, b, h, c, d, x;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &h);
	scanf("%d", &c);
	scanf("%d", &d);
	x = a*b*h/(a*b-c*d);
	printf("%d\n", x);
  return 0;
}
