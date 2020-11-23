#include <stdio.h>
#include <stdlib.h>
int tail[100000];
void split(int A[], int *a[], int *head[], int k){ 
    int Alen = 1, z = 0;
    while(a[z]!=NULL) Alen++, z++;
    for(int i = 0;i<k;i++){
        head[i] = NULL;
        tail[i] = -1;
    }
    for(int i = 0;i<Alen;i++){
        int idx = A[i]%k;
        if(tail[idx] == -1) {
          head[idx] = &A[i];
        }
        else{
          a[tail[idx]] = &A[i];
        }
        tail[idx] = i;
    }
    for(int i = 0; i < k; i++){
        a[tail[i]] = NULL;
    }
    return;
}
