#include <stdio.h>
int main(){
	int a ,b,h,c,d,output;
	scanf("%d %d %d %d %d",&a,&b,&h,&c,&d);
	
output=(a*b*h)/(a*b-c*d);
	printf("%d",output);
} 

