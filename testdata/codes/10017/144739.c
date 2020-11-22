#include <stdio.h>
int main (){
	int n;
	scanf("%d",&n);
	int a[n][2],b[n][2],count=0;
	while (~scanf("%d %d",&a[count][0],&a[count][1])){
		int min=65535;
		for (int i=0;i<count;i++){
			int temp=0;
			temp+=(a[count][0]>b[i][0])? a[count][0]-b[i][0]:b[i][0]-a[count][0];
			temp+=(a[count][1]>b[i][1])? a[count][1]-b[i][1]:b[i][1]-a[count][1];
			if (temp<min){
				min=temp;
			}
		}
		if (count!=0) printf("%d\n",min);
		scanf("%d %d",&b[count][0],&b[count][1]);
		min=65535;
		for (int i=0;i<=count;i++){
			int temp=0;
			temp+=(b[count][0]>a[i][0])? b[count][0]-a[i][0]:a[i][0]-b[count][0];
			temp+=(b[count][1]>a[i][1])? b[count][1]-a[i][1]:a[i][1]-b[count][1];
			if (temp<min){
				min=temp;
			}
		}
		printf("%d\n",min);
		count++;
	}
	return 0;
}
