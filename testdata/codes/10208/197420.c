#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b, h, c, d, hafter;
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	hafter = a*b*h/(a*b - c*d);
	printf("%d", hafter);
	return 0;
}
