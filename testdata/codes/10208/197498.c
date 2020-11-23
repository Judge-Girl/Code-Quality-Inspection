#include<stdio.h>
int main(){
    int a, b, h, c, d, e, f;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	e=a*b*h;
	f=a*b-c*d;
    printf("%d",e/f);
	return 0;
}
