#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k){
    int N = 0;
    while(a[N] != NULL)
        N++;
    N++;
    int **index[100000];
    for (int i = 0; i < k; i++){
        index[i] = &head[i];
        head[i] = NULL;
    }
    for (int i = 0; i < N; i++){
        *index[A[i] % k] = &A[i];
        a[i] = NULL;
        index[A[i] % k] = &a[i];
    }
}
