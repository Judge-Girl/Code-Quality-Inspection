#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k) {
    int **tail[100000] = {};
    int m;
    for ( int i = 0 ; i < k ; i++ ) {
        tail[i] = &head[i];
    }
    int i = 0;
    for ( i = 0 ; a[i] != NULL ; i++ ) {
        a[i] = NULL;
        m = A[i] % k;
        *tail[m] = &A[i];
        tail[m] = &a[i];
    }
    m = A[i] % k;
    *tail[m] = &A[i];

}
