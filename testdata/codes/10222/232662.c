#include <stdio.h>
#include <stdlib.h>

void split(int A[], int *a[], int *head[], int k)
{
    int **tail[k];
    int i;
    for(i=0;i<k;i++){
        head[i]=NULL;
        tail[i]=NULL;
    }
    int p=0;
    int mk;
    int f=1;
    while(f){
        mk=A[p]%k;
        if(head[mk]==NULL){
            head[mk]=&A[p];
        }else{
            (*tail[mk])=&A[p];
        }
        tail[mk]=&a[p];
        if(a[p]==NULL){
            f=0;
        }
        p++;
    }
    for(i=0;i<k;i++){
        if(tail[i]!=NULL){(*tail[i])=NULL;}
    }
    return;
}

