#include <stdio.h>

main(){

int a,b,h,c,d,x;

scanf("%d %d %d %d %d",&a,&b,&h,&c,&d);
x = (a*b*h)/(a*b-c*d);
printf("%d",x);




return 0;
}

