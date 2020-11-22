#include <stdio.h>
#include <stdlib.h>

void split(int A[], int *a[], int *head[], int k){
        int *now[100000];
        int cnt;
        for(cnt = 0; a[cnt] != NULL; cnt++){
                a[cnt] = NULL;
        }
        int *p = A;
        for(int i = 0; i <= cnt; i++){
                int rem = A[i] % k;
                int **q = &head[rem];
                while(*q){
                        q = &a[(*q)-A];
                }
                *q = &A[i];
        }
}

