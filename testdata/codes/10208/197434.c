#include <stdio.h>
int main(){
	int a, b, h, c, d;
	int water, botton;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	water = a*b*h;
	botton = a*b-c*d;
	printf("%d", water/botton);
	return 0;
}

