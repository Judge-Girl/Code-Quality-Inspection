#include <stdio.h>
#include <stdlib.h>

void split(int A[], int *a[], int *head[], int k){
	int **last[k];
	for(int i=0;i<k;i++)
		last[i]=&head[i];
	int count=0;
	while(a[count]!=NULL)
		count++;
	int xulie=0;
	while(xulie<=count){
		int re=A[xulie]%k;
		*last[re]=&A[xulie];
		last[re]=&a[xulie];
		xulie++;
	}
	for(int i=0;i<k;i++)
		*last[i]=NULL;
	return;
}
