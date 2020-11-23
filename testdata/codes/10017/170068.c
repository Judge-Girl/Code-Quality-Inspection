#include <stdio.h>
#include <stdlib.h>

int x[ 2 ][ 50000 ];
int y[ 2 ][ 50000 ];

int manh( int a, int b, int c, int d ){
	return abs( a - b ) + abs( c - d );
}

int min( int a, int b ){
	return a < b ? a : b;
}

int getDis( int t, int oppo, int nx, int ny ){
	int big = 2147483647;
	for( int i = 0; i <= t; i++ )
		big = min( big, manh( x[ oppo ][ i ], nx, y[ oppo ][ i ], ny ) );
	return big;
}

int main(){
	int N;
	scanf("%d", &N );
	for( int i = 0; i < N; i++ ){
		scanf("%d%d", &x[ 0 ][ i ], &y[ 0 ][ i ] );
		if( i != 0 )
			printf("%d\n", getDis( i - 1, 1, x[ 0 ][ i ], y[ 0 ][ i ] ) );

		scanf("%d%d", &x[ 1 ][ i ], &y[ 1 ][ i ] );
		printf("%d\n", getDis( i, 0, x[ 1 ][ i ], y[ 1 ][ i ] ) );
		
	}
}
