#include <stdio.h>
int tail[100000] = {};
void split(int A[], int *a[], int *head[], int k){
	int amountA = 1;
	while(a[amountA - 1] != NULL) amountA++;
	for(int i = 0; i < k; i++) head[i] = NULL;
	for(int i = 0; i < amountA; i++){
		if(tail[A[i] % k] == 0){
			head[A[i] % k] = &A[i];
			tail[A[i] % k] = i + 1;
		}
		else{
			a[tail[A[i] % k] - 1] = &A[i];
			tail[A[i] % k] = i + 1; 
		}
	}
	for(int i = 0; i < k; i++){
		a[tail[i] - 1] = NULL;
	}
	return;
}
