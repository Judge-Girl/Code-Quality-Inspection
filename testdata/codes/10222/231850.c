#include <stdio.h>
void split(int A[], int *a[], int *head[], int k){
	int** tail[k];
	int* N = NULL;
	for(int i=0; i<k; i++)
		tail[i] = &N;
	
	int num;
	for(num=0; a[num]!=NULL; num++);
	num++;
	
	//printf("%d\n",num);
	for(int i=0; i<num; i++){
		int group = A[i]%k;
		//printf("group = %d\n",group);
		if(head[group]==NULL)
			head[group] = &A[i];
		else
			*tail[group] = &A[i];
		tail[group] = &a[i];
	}
	
	for(int i=0; i<k; i++)
		*tail[i]  = N;
}
