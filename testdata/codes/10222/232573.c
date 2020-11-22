#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k)
{
    int **last[k];
    int i,N;
    for(i=0;i<k;i++)
        last[i] = &head[i];
    for(i=0;a[i]!=NULL;i++)
        N=i+1;
    for(i=0;i<=N;i++){
        *last[A[i]%k] = &A[i];
        last[A[i]%k] = &a[i];
        a[i] = NULL;
    }
    return;
}

