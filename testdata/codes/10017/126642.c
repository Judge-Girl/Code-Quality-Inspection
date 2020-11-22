#include <stdio.h>

int Ax[50000], Ay[50000], Bx[50000], By[50000];

int abs(int x) {
	return (x > 0? x: -x);
}

int main() {
	int N, x, y, Mdis;
	scanf("%d\n", &N);
	for(int i = 0; i < N; ++i) {
		Mdis = 70000;
		scanf("%d %d\n", &x, &y);
		Ax[i] = x;
		Ay[i] = y;
		for(int j = 0; j < i; ++j) {
			if(abs(x - Bx[j]) + abs(y - By[j]) < Mdis)
				Mdis = abs(x - Bx[j]) + abs(y - By[j]);
		}
		if(i)
			printf("%d\n", Mdis);
		Mdis = 70000;
		scanf("%d %d\n", &x, &y);
		Bx[i] = x;
		By[i] = y;
		for(int j = 0; j <= i; ++j) {
			if(abs(x - Ax[j]) + abs(y - Ay[j]) < Mdis)
				Mdis = abs(x - Ax[j]) + abs(y - Ay[j]);
		}
		printf("%d\n", Mdis);
	}
	return 0;
}
