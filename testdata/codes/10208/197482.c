#include <stdio.h>
main()
{
int a , b , c , d , h;
scanf("%d%d%d%d%d" , &a , &b , &h , &c , &d);
int i , j , k;
int H;
H = (a*b*h)/(a*b-c*d);
printf("%d" , H);
}
