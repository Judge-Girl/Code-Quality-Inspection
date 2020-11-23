#include <stdio.h>
#include <stdlib.h>
#include "split.h"

void split(int A[], int *a[], int *head[], int k){
    int lenA = 0, idx = 0;
    while(a[idx] != NULL){
        idx++;
        lenA++;
        //printf("%d\n", lenA);
    }
    lenA++;
    idx = 0;
    for(int i = 0; i < lenA; i++) a[i] = NULL;
    /*for(int i = 0; i < k; i++){
        int first = 1, pre;
        for(int j = 0; j < lenA; j++){
            if(A[j]%k == i){
                if(first){
                    head[i] = &A[j];
                    first = 0;
                    pre = j;
                }
                else{
                    a[pre] = &A[j];
                    pre = j;
                }
            }
        }
    }*/
    int tail[k];
    for(int i = 0; i < k; i++) tail[i] = -1;
    for(int i = 0; i < lenA; i++){
        if(tail[A[i]%k] == -1){
            head[A[i]%k] = &A[i];
            tail[A[i]%k] = i;
        }
        else{
            a[tail[A[i]%k]] = &A[i];
            tail[A[i]%k] = i;
        }
    }
}
