#include <stdio.h>

main() {
	int a, b, h, c, d;
	
	scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
	
	//calculate the volume of the tank
	//calculate the volume of the brick
	
	int areaBrick = c*d;
	int areaTank = a*b;
	
	//v = lwh
	//a=lw
	
	
	
	//calculate two areas and subtract
	
	//calculate new height
	
	int newArea = areaTank - areaBrick;
	
	int volumeWater = a * b * h;
	
	int height = volumeWater / newArea;
	
	printf("%d\n",  height);
	
	
	return 0;
	
	
}
