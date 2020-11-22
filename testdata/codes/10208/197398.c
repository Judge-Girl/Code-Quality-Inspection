#include<stdio.h>
#include<stdlib.h>

int main(){
	int a, b, h, c, d;
	scanf("%d %d %d %d %d", &a, &b, &h, &c, &d);
	int v = a * b * h;
	int newA = a * b - c * d;
	int ans = v / newA;
	printf("%d", ans);
    return 0;
}
