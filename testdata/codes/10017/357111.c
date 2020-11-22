#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int player0[30000][2], player1[30000][2];

int main ( ) {
     int N;
     scanf("%d", &N);

     int p, q;
     scanf("%d%d", &player0[0][0], &player0[0][1]);
     for ( int count = 1; count < 2*N; count++ ) {
          scanf("%d%d", &p, &q);
          int min = INT_MAX;
          if ( count%2 != 0 ) {
               for ( int i = 0 ; i < count/2 + 1; i++ ) {
                    if ( abs( player0[i][0] - p ) + abs( player0[i][1] - q ) < min )
                         min = abs( player0[i][0] - p ) + abs( player0[i][1] - q );
               }
               printf("%d\n", min);
               player1[count/2][0] = p;
               player1[count/2][1] = q;
          }
          else {
               for ( int i = 0 ; i < count/2; i++ ) {
                    if ( abs( player1[i][0] - p ) + abs( player1[i][1] - q ) < min )
                         min = abs( player1[i][0] - p ) + abs( player1[i][1] - q );
               }
               printf("%d\n", min);
               player0[count/2][0] = p;
               player0[count/2][1] = q;
          }
     }
     return 0;
}

