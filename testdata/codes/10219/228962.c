#include <stdio.h>
void merge(int A[], int B[], int* a[], int* b[]){
	int len_A=1;
	while(a[len_A-1]!=NULL){
		len_A++;
	}
	int len_B=1;
	while(b[len_B-1]!=NULL){
		len_B++;
	}
	int* ptr_A=A;
	int* ptr_B=B;
	int index_A=0;
	int index_B=0;
	for(int i=0;i<len_A-1;i++){
		while(A[i]>*ptr_B){
			index_B++;
			if(index_B==len_B){
				break;
			}
			ptr_B++;
		}
		if(index_B==len_B){
			for(int j=i;j<len_A-1;j++){
				a[i]=&A[i+1];
			}
			break;
		}
		if(A[i]<*ptr_B){
			
			if(A[i+1]>*ptr_B){
				a[i]=ptr_B;
			}
			else{
				a[i]=&A[i+1];
			}
			continue;
		}
	}
	for(int i=0;i<len_B-1;i++){
		while(B[i]>*ptr_A){
			index_A++;
			if(index_A==len_A){
				break;
			}
			ptr_A++;
		}
		if(index_A==len_A){
			for(int j=i;j<len_B-1;j++){
				b[i]=&B[i+1];
			}
			break;
		}
		if(B[i]<*ptr_A){
			if(B[i+1]>*ptr_A){
				b[i]=ptr_A;
			}
			else{
				b[i]=&B[i+1];
			}
			continue;
		}
	}
	a[len_A-1]=NULL;
	b[len_B-1]=NULL;
	for(int i=0;i<len_B;i++){
		if(B[i]>A[len_A-1]){
			a[len_A-1]=&B[i];
			break;
		}
	}
	for(int i=0;i<len_A;i++){
		if(A[i]>B[len_B-1]){
			b[len_B-1]=&A[i];
			break;
		}
	}
	return;
}
