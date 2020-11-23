#include <stdlib.h>
#include <stdio.h>
int ptr[100000];
void split(int A[], int *a[], int *head[], int k){
	int N = 0,i = 0;
	for(int i = 0;i < k;i++){head[i] = NULL;ptr[i] = -1;}
	while(1){
		if(a[N] != NULL)N++;
		else break;
	}
	N++;

	while(i < N){
		if(head[A[i]%k] == NULL){head[A[i]%k] = &A[i];ptr[A[i]%k] = i;}
		else{
			a[ptr[A[i]%k]] = &A[i];
			ptr[A[i]%k] = i;
		} 
		i++;
	}
	for(int i = 0;i < k;i++){if(ptr[i] != -1){a[ptr[i]]= NULL;}}
	return;
}
