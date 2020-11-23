#include <stdio.h>
#include <stdlib.h>
 int tail[100000] = {0};
 void split(int A[], int *a[], int *head[], int k){
	int n = 0;
	while(a[n] != NULL)
		n++;
	n++;
	for (int i = 0; i < k; i++)
		tail[i] = -1;
	for (int i = 0; i < n; i++){
		if (tail[A[i]%k] == -1){
			head[A[i]%k] = &A[i];
		}
		else{
			a[tail[A[i]%k]] = &A[i];
		}
		tail[A[i]%k] = i;
	}
	for (int i = 0; i < k; i++){
		if (tail[i] == -1) head[i] = NULL;
		a[tail[i]] = NULL;
	}
 }
