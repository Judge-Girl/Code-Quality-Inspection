#include <stdio.h>
void split(int A[], int *a[], int *head[], int k);

void split(int A[], int *a[], int *head[], int k)
{
	int now[100000];
	int num = 0;
	for(int i = 0; a[i] != NULL; i ++)
		num ++;
	num ++;
	for(int i = 0; i < k; i ++)
		now[i] = -1;
	for(int i = 0; i < num; i ++){
		int remain = A[i]%k;
		if(now[remain] == -1){
			head[remain] = &A[i];
		}else{
			a[now[remain]] = &A[i];
		}
		now[remain] = i;
	}
	for(int i = 0; i < k; i ++){
		if(now[i] == -1){
			head[i] = NULL;
		}else{
			a[now[i]] = NULL;
		}
	}
}
