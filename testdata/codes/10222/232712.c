#include <stdio.h>
#include <stdlib.h>

void split(int A[], int *a[], int *head[], int k){
	int tot = 0;
	while (a[tot] != NULL){a[tot] = NULL; tot ++;}
	// printf("%d\n", tot);

	int tail[100004] = {0};
	for (int i = 0; i <= tot; i ++){
		int tmp = A[i] % k;
		// printf("%d\n", tmp);
		if (head[tmp] == NULL){
			head[tmp] = &A[i];
			tail[tmp] = i;
			// printf("head to A[%d] = %d\n", i, A[i]);
		}
		else {
			a[tail[tmp]] = &A[i];
			// printf("a[%d] to A[%d] = %d\n", tail[tmp], i, A[i]);
			tail[tmp] = i;
		}
	}
	return;
}
