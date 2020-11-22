#include <stdio.h>
#include <stdlib.h>
 
int Distance( int a[ 2 ], int b[ 2 ] )
{
	return abs( a[ 0 ] - b[ 0 ] ) + abs( a[ 1 ] - b[ 1 ] );
}
 
int main( void )
{
	int position[ 2 ][ 50000 ][ 2 ] = {0};
	int step_count = 0;
	scanf( "%d", &step_count );
	
	for( int i = 0; i < step_count; i++ )
	{
		scanf( "%d%d", &position[ 0 ][ i ][ 0 ], &position[ 0 ][ i ][ 1 ] );
		if( i != 0 )
		{
			int min_dist = 0x7FFFFFFF;
			for( int j = 0; j < i; j++ )
			{
				int dist = Distance( position[ 0 ][ i ], position[ 1 ][ j ] );
				if( dist < min_dist )
				{
					min_dist = dist;
				}
			}
			
			printf( "%d\n", min_dist );
		}
		
		scanf( "%d%d", &position[ 1 ][ i ][ 0 ], &position[ 1 ][ i ][ 1 ] );
		
		int min_dist = 0x7FFFFFFF;
		for( int j = 0; j <= i; j++ )
		{
			int dist = Distance( position[ 1 ][ i ], position[ 0 ][ j ] );
			if( dist < min_dist )
			{
				min_dist = dist;
			}
		}
		
		printf( "%d\n", min_dist );
	}
	
	return 0;
}
