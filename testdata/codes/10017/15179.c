#include <stdio.h>
#include <stdlib.h>

/*
int distance (int i, int x[][] , int y[][]) {
	int d = 70000 ;
	int j ;
	for (j = 0 ; j < (i+1) / 2 ; j++) {
		if (abs(x[i%2][i/2]-x[(i+1)%2][j]) + abs(y[i%2][i/2]-y[(i+1)%2][j]) < d) {
			d = abs(x[i%2][i/2]-x[(i+1)%2][j]) + abs(y[i%2][i/2]-y[(i+1)%2][j]) ;
		}
	}

	return d ;
}
*/

int main() {
	int N, d ;
	int x[2][50000], y[2][50000] ;
	int i, j ;
	scanf("%d", &N) ;
	scanf("%d %d", &x[0][0], &y[0][0]) ;
	for (i = 1 ; i < 2*N ; i++) {
		d = 70000 ;
		scanf("%d %d", &x[i%2][i/2], &y[i%2][i/2]) ;
		for (j = 0 ; j < (i+1) / 2 ; j++) {
			if (abs(x[i%2][i/2]-x[(i+1)%2][j]) + abs(y[i%2][i/2]-y[(i+1)%2][j]) < d)
				d = abs(x[i%2][i/2]-x[(i+1)%2][j]) + abs(y[i%2][i/2]-y[(i+1)%2][j]) ;
		}
		printf("%d\n", d) ;
	}


	return 0 ;
}
