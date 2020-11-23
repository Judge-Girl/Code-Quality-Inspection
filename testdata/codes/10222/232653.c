#include <stdio.h>
void split(int A[], int *a[], int *head[], int k){
    // get size_a
    //int size_a=1;
    //for(int i=0; a[i]!=NULL; i++, size_a++);

    int **last[100000];
    for(int i=0; i<k; ++i) last[i] = head+i;

    //for(int i=0; i<size_a; i++){
    for(int i=0; ; ++i){
        int dest = A[i]%k;
        *last[dest] = A+i;
        last[dest] = a+i;
        if(a[i] == NULL) break;
    }

    for(int i=0; i<k; ++i) *last[i] = NULL;
}
