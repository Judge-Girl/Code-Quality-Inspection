#include<stdio.h>
int main(){
	int a,b,h,c,d;
	scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
	int s =  a*b*h/(a*b - c*d);
	printf("%d",s);
	
	return 0;
	
}
