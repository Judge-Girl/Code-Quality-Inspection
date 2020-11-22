#include <stdio.h>

int main(int argc, char* argv[])
{
	int a,b,h,c,d;
	int depth;
	int v0;
	
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &h);
	scanf("%d", &c);
	scanf("%d", &d);
	
	v0=a*b*h;
	depth=v0/(a*b-c*d);
	

	printf("%d", depth);
	
	return 0;
}

