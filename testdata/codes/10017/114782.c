#include <stdio.h>

int main(){
	int n, arr[100000][2];
	scanf("%d", &n);
	n *= 2;
	for(int i = 0; i < n; i++){
		int length = 2147483647, a, b, c, d;
		scanf("%d%d", &arr[i][0], &arr[i][1]);
		a = arr[i][0];
		b = arr[i][1];
		int r;
		if(i % 2 == 0){
			r = 1;
		}
		else{
			r = 0;
		}
		for(int j = r; j < i; j += 2){
			c = arr[j][0];
			d = arr[j][1];
			int x = (a - c > 0 ? (a - c) : (c - a));
			int y = (b - d > 0 ? (b - d) : (d - b)); 
			if(length > x + y){
				length = x + y;
			} 
		}	
		if(i != 0){
			printf("%d\n", length);
		}
	}
	return 0;
} 
