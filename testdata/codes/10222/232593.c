#include <stdio.h>
#include <stdlib.h>
#include "split.h"

void split(int A[], int *a[], int *head[], int k){
    int N=0;
    for(;a[N]!=NULL;N++);
    N++;
    int tAil[k];
    for(int i=0;i<k;i++)
        tAil[i]=-1;
    for(int i=0;i<N;i++){
        int K=A[i]%k;
        if(tAil[K]==-1){
            head[K]=&A[i];
            tAil[K]=i;
            continue;
        }
        a[tAil[K]]=&A[i];
        tAil[K]=i;
    }
    for(int i=0;i<k;i++){
        a[tAil[i]]=NULL;
    }
}
