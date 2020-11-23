#include <stdio.h>
#include <stdlib.h>

void split(int A[], int *a[], int *head[], int k){
    //get the size of A
    int count=1; //count is the size of A
    int i=0;
    int tail[100000]={0};
    while(a[i]!=NULL){
        count++;
        i++;
    }
    for (int i = 0; i < count; ++i)
        a[i] = NULL;
    //the size of head is k
    int idxA=0;
    while(idxA<count){
        int mod= (A[idxA] %k);
        if(head[mod]==NULL){
            head[mod]= &A[idxA];
            tail[mod]= idxA;
        }
        else{
            a[tail[mod]] = &A[idxA];
            tail[mod] = idxA;
        }
        idxA++;
    }
}
