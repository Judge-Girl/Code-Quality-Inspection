#include "split.h"
#include <stdio.h>

int last[100001];

void split(int A[], int *a[], int *head[], int k){
	for(int i = 0 ; head[i] != NULL ; i ++){
		head[i] = NULL;
	}
    int la = 0;
    for(; a[la] != NULL ; la ++);
    la ++;
for(int i = 0 ; i < k ; i ++)
	last[i] = -1;
    for(int t = 0 ; t < la ; t ++){
        int num = A[t] % k;
        if(last[num] == -1){
        	head[num] = &A[t];
        	a[t] = NULL;
        	last[num] = t;
        }
        else{
            a[last[num]] = &A[t];
            last[num] = t;
            a[last[num]] = NULL;
        }
    }
    return;
}
