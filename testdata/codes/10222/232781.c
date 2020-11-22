#include<stdio.h>
#include<string.h>
void split(int A[], int *a[], int *head[], int k){
	int num,h[100001];
	for(int i=0;i<110001;i++){
		if(a[i]==NULL){
			num=i;
			break;
		}
	}
	for(int i=0;i<=num;i++){
		int r=A[i]%k;
		if(head[r]==NULL){
			head[r]=&A[i];
			h[r]=i;
		}
		else{
			a[h[r]]=&A[i];
			h[r]=i;
		}
	}
	for(int i=0;i<k;i++){
		if(head[i]!=NULL)a[h[i]]=NULL;
	}
}

