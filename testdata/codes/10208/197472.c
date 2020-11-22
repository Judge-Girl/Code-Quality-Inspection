#include <stdio.h>

main()
{
	 int a, b, h, c, d, h1;
	 scanf("%d%d%d%d%d" , &a, &b, &h, &c, &d);
	 h1 = a*b*h/(a*b-c*d);
	 printf("%d\n" , h1);
}

