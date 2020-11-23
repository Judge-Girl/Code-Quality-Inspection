#include <stdlib.h>
#include <stdio.h>

void split(int A[], int *a[], int *head[], int k)
{
    int tail[k];
    int i;
    for ( i = 0; a[i] != NULL; i++) {
        int r = A[i] % k;
        if ( head[r] == NULL ) {
            head[r] = &A[i];
            tail[r] = i;
            a[i] = NULL;
        } else {
            a[ tail[r] ] = &A[i];
            tail[r] = i;
            a[i] = NULL;
        }
    }
    int r = A[i] % k;
    if ( head[r] == NULL ) {
        head[r] = &A[i];
    } else {
        a[ tail[r] ] = &A[i];
    }
}
 

