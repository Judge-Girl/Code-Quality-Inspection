#include <stdio.h>
void merge(int A[], int B[], int* a[], int* b[]){
	int a_count=0,b_count=0;
	int A_count=0,B_count=0;
	int num_A=0,num_B=0;
	while(a[num_A]!=NULL)
		num_A++;
	while(b[num_B]!=NULL)
		num_B++;
	int now;
	if(A[0]<B[0]){
		now=0;
		A_count++;
	}else{
		now=1;
		B_count++;
	}
			/*0=a,1=b*/
	while(A_count<=num_A&&B_count<=num_B){
		if(A[A_count]<B[B_count]){
			if(now){
				b[b_count]=&(A[A_count]);
				b_count++;
			}else{
				a[a_count]=&(A[A_count]);
				a_count++;
			}
			A_count++;
			now=0;
		}else{
			if(now){
				b[b_count]=&(B[B_count]);
				b_count++;
			}else{
				a[a_count]=&(B[B_count]);
				a_count++;
			}
			B_count++;
			now=1;

		}
	}
	if(A_count>num_A){
		a[a_count]=&(B[B_count]);
	}
	if(B_count>num_B){
		b[b_count]=&(A[A_count]);
	}
	return;
}
