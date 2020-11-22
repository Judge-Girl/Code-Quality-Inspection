#include <stdio.h>
#include <stdlib.h>
#include "split.h"
void split(int A[], int *a[], int *head[], int k) {
    int n;
    for(n = 0; a[n] != NULL; n++);
    n++;
     
    for(int i = 0; i < n; i++) a[i] = NULL;
    // printf("n %d\n", n)
    int last = -1;
    int tail[k+1];

    for(int i = 0 ; i < n; i++) {
        int num = A[i]%k;
        if(head[num] == NULL) {
            head[num] = &A[i];
            tail[num] = i;
        }
        else {
            a[tail[num]] = &A[i];
            tail[num] = i;
        }
    }
}
