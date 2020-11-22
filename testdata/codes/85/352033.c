#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#define max_n 1000000

typedef struct{
     int y, m, d;
}data_;
data_ date[max_n];

int compare( const void *data1, const void *data2 ){
     data_ *date1 = (data_*) data1;
     data_ *date2 = (data_*) data2;

     if ( date1->y != date2->y )
          return (date1->y - date2->y);
     else if ( date1->m != date2->m )
          return (date1->m - date2->m);
     else if ( date1->d != date2->d )
          return (date1->d - date2->d);
     else
          return 0;
}

int main(){
     int n;
     scanf("%d", &n);
     assert(n <= max_n);

     int x, y;
     for ( int k = 0; k < n; k++ ){
          scanf("%d%d%d", &date[k].y, &date[k].m, &date[k].d);
     }

     qsort(date, n, sizeof(data_), compare);

     for ( int k = 0; k < n; k++ ){
          printf("%d %d %d\n", date[k].y, date[k].m, date[k].d);
     }


     return 0;
}

