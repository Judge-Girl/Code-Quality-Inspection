#include<stdio.h>
int main(){
int a, b, c, d, h, tall;
scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
tall=a*b*h/(a*b-c*d);
printf("%d", tall);
}
