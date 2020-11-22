#include <stdio.h>
#include <stdlib.h>

void split(int A[], int *a[], int *head[], int k){
    int size = 1;
    for (int i = 0; a[i] != NULL; ++i)
        size++;
    int tail[100000]; 
    for (int i = 0; i < size; ++i){
        tail[i] = 0; a[i] = NULL;
    }

    for (int i = 0; i < size; ++i){
        int t = A[i] % k;
        if(head[t] != NULL)
            a[tail[t]] = &A[i];
        else
            head[t] = &A[i];
        tail[t] = i;
    }
}
