#include<stdio.h>
int main(){
	int a,b,h,c,d;
	scanf("%d %d %d %d %d",&a,&b,&h,&c,&d);
	printf("%d",a*b*h/(a*b-c*d));
}
//a*b*h=a*b*x-c*d*x
//x=a*b*h/(a*b-c*d)

