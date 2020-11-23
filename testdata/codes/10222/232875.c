#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k){
	int size = 0;
	while(a[size] != NULL){
		size++;		
	}
	size ++;
	//printf("%d\n",size);
	int tail[100000];
	for(int i = 0;i < k;i++){
		tail[i] = -1;
	}
	for(int i = 0;i < size;i++){
		int remainer = A[i]%k;
		if(tail[remainer] == -1){
			head[remainer] = &A[i];
		}else {
			a[tail[remainer]] = &A[i];
		}
		tail[remainer] = i;
	}
	for(int i = 0;i < size;i++){
		if(a[i] == &A[i+1] & A[i+1]%k != A[i]%k){
			a[i] = NULL;
		}
	}
}
