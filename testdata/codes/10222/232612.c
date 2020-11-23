#include <stdio.h>
#include <stdlib.h>
int current[1000000] = {0};
void split(int A[], int *a[], int *head[], int k){
    int sizea = 0;
    while(a[sizea] != NULL){
        sizea++;
    }
    sizea++;
    for(int i = 0; i < sizea; i++){
        int remain = A[i] % k;
        if(head[remain] == NULL){
            head[remain] = &A[i];
            current[remain] = i;
        }
        else{
            a[current[remain]] = &A[i];
            current[remain] = i;
        }
    }
    for(int i = 0; i < k; i++){
        if(head[i] != NULL){
            a[current[i]] = NULL;
        }
    }
    return;
}
