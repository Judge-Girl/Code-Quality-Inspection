#include <stdio.h>
#include <stdlib.h>
#include "split.h"
 
void split(int A[], int *a[], int *head[], int k){
	for(int i=0; i<k; i++){
		head[i] = NULL;
	}
	int current[k];
	int i = 0;
	while(a[i]!=NULL){
		a[i] = NULL;
		int num = A[i]%k;
		if(head[num]==NULL){
			head[num] = &A[i];
		}
		else{
			a[current[num]] = &A[i];
		}
		current[num] = i;
		i++;
	}
	int num = A[i]%k;
	if(head[num]==NULL){
		head[num] = &A[i];
	}
	else{
		a[current[num]] = &A[i];
	}
}
