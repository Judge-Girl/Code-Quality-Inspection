#include <stdio.h>

int min(int a, int b){
	return ((a < b)? a : b);
}

int abs(int a){
	return (a < 0)? -a : a;
}

int main(){
	int n, a[2][50005][2], p = 0, pp[2] = {0};
	scanf("%d", &n);
	n = 2*n;
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &a[p][pp[p]][0], &a[p][pp[p]][1]);
		if (i){
			int mn = 2147483647;
			for (int j = 0; j < pp[!p]; ++j)
				mn = min(mn, abs(a[p][pp[p]][0] - a[!p][j][0]) + abs(a[p][pp[p]][1] - a[!p][j][1]));
			printf("%d\n", mn);
		}
		++pp[p];
		p = !p;
	}
}
