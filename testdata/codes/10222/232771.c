#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k)
{
	int i = 0;
	int j = 0;
	int n = 1;
	int visited[100000] = {0}; // for k's
	while(a[i] != NULL){
        n++;
        i++;
    }
    for (i = 0; i < k; i++)
    	head[i] = NULL;

    // process head to A
    int first[100000] = {0};
	
	// for (i = 0; i < k; i++)  {
	// 	if (head[i] == NULL)  {
	// 		printf("NULL\n");
	// 		continue;
	// 	}
	// 	printf("first is %d\n", first[i]);
	// }
	// int next;
	// // process a to A
	// for (i = 0; i < k; i++)  {
	// 	if (head[i] == NULL)
	// 		continue;
	// 	next = first[i];
	// 	for (j = next+1; j < n; j++)  {
	// 		if (A[j]%k == i)  {
	// 			a[next] = &A[j];
	// 			next = j;
	// 		}
	// 	}
	// 	if (j == n)
	// 		a[next] = NULL;
	// }
	for (i = 0; i < n; i++)
		a[i] = NULL;

	// debug
	for (i = 0; i < n; i++)  {
				if (visited[A[i]%k] == 0)
				{
					head[A[i]%k] = &A[i];
					first[A[i]%k] = i;
					visited[A[i]%k] = 1;
					continue;
				}
				a[first[A[i]%k]] = &A[i];
				first[A[i]%k] = i;
	}


}
