#include<stdio.h>
#include<math.h>
int ax[50000], ay[50000], bx[50000], by[50000];
int main(){
	int n;
	scanf("%d%d%d%d%d", &n, &ax[0], &ay[0], &bx[0], &by[0]);
	printf("%d\n", abs(ax[0]-bx[0])+abs(ay[0]-by[0]));
	for(int i=1; i<n; i++){
		scanf("%d%d%d%d", &ax[i], &ay[i], &bx[i], &by[i]);
		int t=abs(ax[i]-bx[i-1])+abs(ay[i]-by[i-1]);
		for(int j=0; j<i-1; j++){
			int tt=abs(ax[i]-bx[j])+abs(ay[i]-by[j]);
			if(tt<t)
				t=tt;
		}
		printf("%d\n", t);
//		printf("%d %d\n%d %d\n%d\n\n", bx[i-1], by[i-1], ax[i], ay[i], t);
		t=abs(ax[i]-bx[i])+abs(ay[i]-by[i]);
		for(int j=0; j<i; j++){
			int tt=abs(ax[j]-bx[i])+abs(ay[j]-by[i]);
			if(tt<t)
				t=tt;
		}
		printf("%d\n", t);
//		printf("%d %d\n%d %d\n%d\n\n", ax[i], ay[i], bx[i], by[i], t);
	}
}

