#include <stdio.h>
#include <stdlib.h>
#include "split.h"

int idx_arr[100000];
int total_arr[100000];
void split(int A[], int *a[], int *head[], int k){
	int len = 0;
	while(a[len] != NULL) len++;
	len++;
	// printf("%d\n", len);
	for(int i=0; i<k; i++)
		idx_arr[i] = -1;
	for(int i=0; i<len; i++){
		// printf("A[%d] = %d\n", i, A[i]);
		int number = A[i] % k;
		// printf("number = %d\n", number);
		// total_arr[number]++;

		
		if(idx_arr[number] == -1 /*&& head[idx_arr[number]] == NULL*/){
			head[number] = &A[i];
			idx_arr[number] = i;
			// printf("idx_arr[%d] = %d\n", number, idx_arr[number]);
		}else{
			// printf("i\n");
			a[idx_arr[number]] = &A[i];
			idx_arr[number] = i;
		}
		
	}

	for(int i=0; i<k; i++){
		a[idx_arr[i]] = NULL;
	}
}


// int main(int argc, char const *argv[])
// {
//     int N, k;
//     scanf("%d%d", &N, &k);
//     int A[N];
//     for (int i = 0; i < N; ++i)
//         scanf("%d", &A[i]);
//     int *a[N], *head[k];
//     for (int i = 0; i < N-1; ++i)
//         a[i] = &A[i+1];
//     a[N-1] = NULL;
//     for (int i = 0; i < k; ++i)
//         head[i] = NULL;
//     split(A, a, head, k);
//     for (int i = 0; i < k; ++i) {
//         if (head[i] == NULL)
//             printf("NULL\n");
//         else {
//             int *tmp = head[i];
//             printf("%d", *tmp);
//             tmp = *(tmp-A+a);
//             while (tmp != NULL) {
//                 printf(" %d", *tmp);
//                 tmp = *(tmp-A+a);
//             }
//             printf("\n");
//         }
//     }
//     return 0;
// }
