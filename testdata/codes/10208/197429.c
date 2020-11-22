#include <stdio.h>

int main(){
	int a,b,h,c,d;
	scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
	int v=a*b*h, tmp=a*b-c*d;
	int ans= v/tmp;
	printf("%d\n",ans);
	return 0;
}
