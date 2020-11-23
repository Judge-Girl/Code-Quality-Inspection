#include"split.h"

int** tail[100000] = {};

void split(int A[], int *a[], int *head[], int k){
	int count = 0;
	while(a[count]){
		count++;
	}
	int i = 0;
	while(i <= count){
		int group = A[i]%k;
		if(!tail[group]){
			head[group] = &A[i];
			tail[group] = &a[i];
			a[i] = 0;
		}else{
			*(tail[group]) = &A[i];
			tail[group] = &a[i];
			a[i] = 0;
		}
		i++;
	}
	
}

