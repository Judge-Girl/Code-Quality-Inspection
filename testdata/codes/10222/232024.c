#include <stdio.h>

void split(int A[], int *a[], int *head[], int k) {
    static int **p[100000];
    for (int i = 0; i < k; ++i) p[i] = &head[i];
    for (int i = 0; ; ++i) {
        *p[A[i] % k] = &A[i];
        p[A[i] % k] = &a[i];
        if (!a[i]) break;
        *p[A[i] % k] = NULL;
    }
}

