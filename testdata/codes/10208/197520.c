// Exam #1 intr. to prog.

#include <stdio.h>

int main() {
	
	int a;
	int b;
	int h;
	int c;
	int d;
	int v;
	int nh;
	
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &h);
	scanf("%d", &c);
	scanf("%d", &d);
					
	
	v = a * b * h;
	nh = v / (a*b - c*d);
	
	printf("%i\n", nh);
	system("pause");
	return 0;
	
}

