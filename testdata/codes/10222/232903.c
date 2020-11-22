#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k);
/*int main(int argc, char const *argv[])
{
    int N, k;
    scanf("%d%d", &N, &k);
    int A[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
    int *a[N], *head[k];
    for (int i = 0; i < N-1; ++i)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for (int i = 0; i < k; ++i)
        head[i] = NULL;
    split(A, a, head, k);
    for (int i = 0; i < k; ++i) {
        if (head[i] == NULL)
            printf("NULL\n");
        else {
            int *tmp = head[i];
            printf("%d", *tmp);
            tmp = *(tmp-A+a);
            while (tmp != NULL) {
                printf(" %d", *tmp);
                tmp = *(tmp-A+a);
            }
            printf("\n");
        }
    }
    return 0;
}*/

int tail[1000000];
int temp[1000000];
void split(int A[], int *a[], int *head[], int k){
int count = 1;
	for (int i = 0 ; a[i] != NULL ; i ++){
		tail[A[i]%k] = i;
		count ++;
	}
	tail[A[count-1]%k] = count-1;
	for (int i = 0 ; i < count ; i ++){
		if (head[A[i] % k] == NULL){
			head[A[i] % k] = &A[i];
			temp[A[i]%k] = i;
			if (i == tail[A[i]%k]) 
				a[i] = NULL;
		}
		else {
			a[temp[A[i] % k]] = &A[i];
			temp[A[i] % k] = i;
			if (i == tail[A[i]%k]) 
				a[i] = NULL;
		}
	} 
	return;
}
