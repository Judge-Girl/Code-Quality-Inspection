#include <stdio.h>
int main(){
	int a, b, h;
	int c, d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	int H = a*b*h / (a*b-c*d);
	printf("%d", H);
	return 0;
}
