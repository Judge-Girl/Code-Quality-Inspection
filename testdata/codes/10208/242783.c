#include <stdio.h>
 
int main(void){
	int a, b, h, c, d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	int area = a * b - c * d;
	printf("%d", (a * b * h) / area);
	return 0;
}
