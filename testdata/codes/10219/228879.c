#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int A[], int B[], int* a[], int* b[]){
int** pre;
int anum = 0;
int bnum = 0;
if(A[0]<B[0])pre=a;else pre = b;

int af = 0;
int bf = 0;
if(*pre==NULL){if(A[0]<B[0])af=1;else bf=1;}
while(af==0||bf==0){
	#ifdef DEBUG
		printf("%d %d %d %d \n",anum,bnum,A[anum],B[bnum]);
	#endif
if(af){*pre = &B[bnum];pre = &b[bnum++];if(*pre==NULL)bf=1;}
else if(bf){*pre = &A[anum];pre = &a[anum++];if(*pre==NULL)af=1;}
else if(A[anum]<B[bnum]){

	*pre = &A[anum];
	pre = &a[anum++];
	if(*pre==NULL)af=1;
}else{
	*pre = &B[bnum];
	pre = &b[bnum++];
	if(*pre==NULL)bf=1;}
	#ifdef DEBUG
		printf("%d %d \n",af,bf);
	#endif

}
//printf("%d\n",*a[3]);
}

