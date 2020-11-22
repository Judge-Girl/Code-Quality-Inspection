#include <stdio.h>
main()
{
      int x1[50000],y1[50000],x2[50000],y2[50000] ;
      int n ;
      int m ;
      int x[5000][5000] ;
      
      scanf("%d" , &n);
      scanf("%d%d%d%d" , &(x1[0]) , &(y1[0]) , &(x2[0]) , &(y2[0])) ;
      m = abs((x1[0]) - (x2[0])) + abs((y1[0]) - (y2[0])) ;
      printf("%d\n",m);
      
      for( int i = 1 ; i < n ; i++){
           m = 99999 ;
           scanf("%d%d", &(x1[i]) , &(y1[i]) ) ;
                   for( int k = 0 ; k < i ; k++){
                        x[i][k] = abs((x1[i]) - (x2[k])) + abs((y1[i]) - (y2[k])) ;
                        if ( x[i][k] < m ){
                        m = x[i][k] ;}
                        }
                        
                        
                   
                   printf("%d\n", m);
           
           m = 99999 ;
           scanf("%d%d", &(x2[i]) , &(y2[i]) ) ;
                   for( int k = 0 ; k <= i ; k++){
                        x[k][i] = abs((x1[k]) - (x2[i])) + abs((y1[k]) - (y2[i])) ;
                        if ( x[k][i] < m ){
                        m = x[k][i] ;}
                        }
                        
                   printf("%d\n", m);
                   }
}

