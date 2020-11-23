#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct Date{
	int Y;
	short int M;
	short int D;
}date;
int compare(const void *data1,const void *data2){
	date *ptr1 = (date *)data1;
	date *ptr2 = (date *)data2;
	if(ptr1->Y > ptr2->Y) return 1;
	if(ptr1->Y == ptr2->Y && ptr1->M > ptr2->M) return 1;
	if(ptr1->Y == ptr2->Y && ptr1->M == ptr2->M && ptr1->D > ptr2->D) return 1;
	return -1;
}
int main(){
	int n;
	scanf("%d",&n);
	int i = n;
	date A[1000000];
	while(i--){
		scanf("%d %hd %hd",&A[i].Y,&A[i].M,&A[i].D);
	}
	qsort(A,n,sizeof(date),compare);
	i = 0;
	while(i < n){
		printf("%d %hd %hd\n",A[i].Y,A[i].M,A[i].D);
		i++;
	}
	return 0;
}

