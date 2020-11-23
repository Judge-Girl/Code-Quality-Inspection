#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k){
    int i=0, remain;
    while(a[i]!=NULL){
        i++;
    }
    int len=i+1;
    int last[100010], usedh[100010], useda[100010];
    for(i=0; i<k; i++){
        last[i]=0;
    }
    for(i=0; i<len; i++){
        useda[i]=0;
    }
    for(i=0; i<len; i++){
        remain=A[i]%k;
        if(head[remain]==NULL){
            head[remain]=&A[i];
            last[remain]=i;
            usedh[i]=1;
        }
        else{
            a[last[remain]]=&A[i];
            useda[last[remain]]=1;
            last[remain]=i;
        }
    }
    for(i=0; i<len; i++){
        if(useda[i]==0){
            a[i]=NULL;
        }
    }
    return;
}
