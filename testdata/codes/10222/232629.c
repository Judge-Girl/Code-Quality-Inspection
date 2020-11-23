#include <stdio.h>
#include <stdlib.h>
#include "split.h"

void split(int A[], int *a[], int *head[], int k){
    int p[k][2];
    int n=0;
    while(a[n++]!=NULL);
    for(int i=0;i<k;i++){
        p[i][0]=0;
        p[i][1]=0;
    }
    for(int j=0;j<n;j++){
        int i=A[j]%k;
        if(p[i][0]==0){
            head[i]=&A[j];
            p[i][0]=1;
            p[i][1]=j;
        }
        else {
            a[p[i][1]]=&A[j];
            p[i][1]=j;
        }
    }
    for(int i=0;i<k;i++){
        if(p[i][0]!=0){
            a[p[i][1]]=NULL;
        }
    }
}

