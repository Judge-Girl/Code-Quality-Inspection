#include <stddef.h>
int **rem[100001];

void split(int A[], int *a[], int *head[], int k){
for(int i =0;i<k;i++){
rem[i] = &head[i];
head[i] = NULL;
}
int ain = 0;

while(1){
*rem[A[ain]%k] = &A[ain];
rem[A[ain]%k] = &a[ain];


if(a[ain]==NULL)return;
a[ain] = NULL;
ain++;
}

}
