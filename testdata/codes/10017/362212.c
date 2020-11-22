#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct point{
    int x;
    int y;
}Point;



void print( Point a, Point *b, int n ){

    int min = INT_MAX;
    for( int i = 0 ; i <= n ; ++i )
        if( abs( b[ i ].x - a.x ) + abs( b[ i ].y - a.y ) < min )
            min = abs( b[ i ].x - a.x ) + abs( b[ i ].y - a.y );
    printf( "%d\n",min );

}

int main( ){

    Point a[ 50000 ], b[ 50000 ];
    int n;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d %d", &a[ i ].x, &a[ i ].y );
        if( i != 0 )
            print( a[ i ], b, i - 1 );
        scanf("%d %d", &b[ i ].x, &b[ i ].y );
        print( b[ i ], a, i );
    }

    return 0;
}

