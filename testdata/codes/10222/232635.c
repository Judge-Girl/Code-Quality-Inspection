#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k){
	int size_A=1;
	int index=0;
	int pre_index[k];
	while(a[index]!=NULL){
		size_A++;
		index++;
	}
	for(int i=0;i<size_A;i++){
		a[i]=NULL;
	}
	for(int i=0;i<size_A;i++){
		int re=A[i]%k;
		if(head[re]==NULL){
			head[re]=&A[i];
			pre_index[re]=i;
		}
		else{
			a[pre_index[re]]=&A[i];
			pre_index[re]=i;
		}
	}
	return;
}
