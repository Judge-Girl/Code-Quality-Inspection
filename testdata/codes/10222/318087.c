#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k){
	int **tail[k];
	for(int i=0;i<k;i++){
		head[i]=NULL;
		tail[i]=NULL;
	}
	int count=0;
	while(a[count]!=NULL)
		count++;
	count++;
	
	for(int i=0;i<count;i++){
		int p=A[i]%k;
		if(head[p]==NULL){
			head[p]=&(A[i]);
			tail[p]=&(a[i]);
		}
		else{
			(*(tail[p]))=&(A[i]);
			tail[p]=&(a[i]);
		}
	}
	for(int i=0;i<k;i++){
		if(tail[i]!=NULL)
		*(tail[i])=NULL;
	}
	
}
