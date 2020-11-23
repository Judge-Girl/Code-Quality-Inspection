#include <stdio.h>

int main(){
	int a, b, c, d, h , x;
	scanf("%d%d%d%d%d" , &a , &b , &h , &c , &d);
	x = a * b * h / (a * b - c * d);
	printf("%d" , x);
	return 0;
} 

