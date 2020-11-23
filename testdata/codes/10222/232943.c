#include <stdio.h>
#include <stdlib.h>
//#include "split.h"

int **temp[100000];
void split(int A[], int *a[], int *head[], int k){
    int last=0, i=0, num=0;
    while(a[i]!=NULL) i++;
    num=i+1;
    //printf("%d\n",num);
    for(last=0;last<k;last++){
    	temp[last] = &head[last];
	}
	for(i=0;i<num;i++){
		*(temp[A[i]%k]) = &A[i];
		temp[A[i]%k] = &a[i];
	}
	for(last=0;last<k;last++){
		*(temp[last]) = NULL;
	}
}
