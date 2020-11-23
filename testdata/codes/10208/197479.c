#include <stdio.h>
int main () {
	int a,b,h,c,d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	int volume = a*b*h;
	int area = c*d;
	int area1 = a*b;
	
	printf("%d\n", volume/(area1-area));
	return 0;
}
