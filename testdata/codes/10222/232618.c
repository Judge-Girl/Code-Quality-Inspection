#include <stdio.h>
void split(int A[], int *a[], int *head[], int k){
    // get size_a
    int size_a=1;
    for(int i=0; a[i]!=NULL; i++, size_a++);

    int **last[100000];
    for(int i=0; i<k; i++) last[i] = &(head[i]);

    for(int i=0; i<size_a; i++){
        *last[A[i]%k] = &(A[i]);
        last[A[i]%k] = &(a[i]);
    }

    for(int i=0; i<k; i++) *last[i] = NULL;

    /*for(int i=0; i<k; i++){
        int **prev = &(head[i]);
        for(int j=0; j<size_a; j++){
            if(A[j]%k == i){
                *prev = &(A[j]);
                prev = &(a[j]);
            }
        }
        *prev = NULL;
    }*/
}
