#include <stdio.h>
int judge[100000] = {0};
void split(int A[], int *a[], int *head[], int k){
	int **idx[100000] = {NULL} , num = 0;
	int s = 0;
	for(int j = 0 ; s != 1; j++){
		int now = A[j]%k;
		if(!judge[now]){
			head[now] = &A[j];
			idx[now] = &a[j];
			judge[now] = 1;
		}
		else{
			*idx[now] = &A[j];
			idx[now] = &a[j];
		}
		if(a[j] == NULL) s = 1;
	}
	for(int i = 0 ; i < k; i++){
		if(idx[i] != NULL)
			*idx[i] = NULL;
	}
}
/*#include <stdlib.h>
int main(int argc, char const *argv[])
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
