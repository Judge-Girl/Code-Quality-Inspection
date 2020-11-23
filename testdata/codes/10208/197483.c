#include <stdio.h> 

int main(void){
	int a, b, h, c, d, depth = 0;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	depth = a*b*h/(a*b-c*d);
	printf("%d", depth);
}
