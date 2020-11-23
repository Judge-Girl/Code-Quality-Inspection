#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k)
{
    int i = 0;
    int size_l = 1;
    int j;
    int last_idx[k];
    while(a[i] != NULL){
        i++;
        size_l++;
    }
    int list_idx = 0;
    for(i = 0; i < size_l; i++){
        int idx = A[i] % k;
        if(head[idx] == NULL){
            head[idx] = &A[i];
            last_idx[idx] = i;
        }
        else{
            a[last_idx[idx]] = &A[i];
            last_idx[idx] = i;
        }
    }
    for(i = 0; i < k; i++){
        if(head[i] != NULL){
            a[last_idx[i]] = NULL;
        }
    }
}
