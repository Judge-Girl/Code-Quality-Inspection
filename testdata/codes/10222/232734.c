#include <stdio.h>
#include <stdlib.h>
int tmp[100000+1],tail[100000+1],count = 0;
void split(int A[], int *a[], int *head[], int k){
	for(int i = 0; a[i]!= NULL; i++){
		tail[A[i]%k] = i;
		count = i;
	}
	if(count == 0) count++;
	else count+=2;
	//printf("count %d\n", count);
	tail[A[count-1]%k] = count-1;
	for(int i = 0; i < count; i++)
	{
		if(head[A[i]%k] == NULL){
			head[A[i]%k] = &A[i];
			tmp[A[i]%k] = i;
			if(i == tail[A[i]%k]) 
				a[i] = NULL;
		}
		else {
			a[tmp[A[i]%k]] = &A[i];
			tmp[A[i]%k] = i;
			if(i == tail[A[i]%k])
			 a[i] = NULL;
		}
	}
}
