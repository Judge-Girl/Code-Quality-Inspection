#include<stdio.h>
int main(){
	int a,b,h,c,d;
	scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
	int volumeair,areabrick;
	volumeair=a*b*h;
	//printf("volumeair=%d\n",volumeair);
	areabrick=c*d;
	//printf("areab=%d\n",volumeair);
	int areawater;
	areawater=a*b-areabrick;
//	printf("areaw=%d\n",volumeair);
	int newh;
	newh=volumeair/areawater;
	printf("%d\n",newh);
} 
