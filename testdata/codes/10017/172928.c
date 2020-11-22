#include <stdio.h>
#include <math.h>
int a[50000][2];
int b[50000][2];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		int min = 70000;
		for(int j = 0 ;j<i;j++){
			if(abs(a[i][0]-b[j][0])+abs(a[i][1]-b[j][1]) < min) 
				min = abs(a[i][0]-b[j][0])+abs(a[i][1]-b[j][1]);
		}
		if(min != 70000) printf("%d\n",min);
		min = 70000;
		scanf("%d%d",&b[i][0],&b[i][1]);
		for(int j = 0 ;j<=i;j++){
			if(abs(b[i][0]-a[j][0])+abs(b[i][1]-a[j][1]) < min)
				min = abs(b[i][0]-a[j][0])+abs(b[i][1]-a[j][1]);
		}
		printf("%d\n",min);
	}
}
