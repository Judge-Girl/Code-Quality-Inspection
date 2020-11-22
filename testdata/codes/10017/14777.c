#include <stdio.h>
int main (void) {
	int i, j, N, x, y, ts, x1[50005], x2[50005], y1[50005], y2[50005], s1[50005]={0}, s2[50005]={0};
	scanf("%d", &N);
	for (i=0; i<N; i++) 
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
	x=x1[0]-x2[0];
	y=y1[0]-y2[0];
	if (x<0)
		x*=-1;
	if (y<0)
		y*=-1;
	s2[0]=x+y;
	for (i=1; i<N; i++) {
		for (j=i; j>=0; j--) {
			if (i!=j) {
				x=x1[i]-x2[j];
				y=y1[i]-y2[j];
				if (x<0)
					x*=-1;
				if (y<0)
					y*=-1;
				ts=x+y;
				if (s1[i]==0 || s1[i]>ts)
					s1[i]=ts;					
			}
			x=x1[j]-x2[i];
			y=y1[j]-y2[i];
			if (x<0)
				x*=-1;
			if (y<0)
				y*=-1;
			ts=x+y;
			if (s2[i]==0 || s2[i]>ts)
				s2[i]=ts;
		}
	}
	printf("%d\n", s2[0]);
	for (i=1; i<N; i++)
		printf("%d\n%d\n", s1[i], s2[i]);
	return 0;
}
