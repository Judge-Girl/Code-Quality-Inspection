#include <stdio.h>

int main(){
	int a, b, h, c, d;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	int n = a * b - c * d;
	printf("%d", a * b * h / n);
	
	return 0;
}
