#include <stdio.h>

void split(int A[], int *a[], int *head[], int K)
{
  int count = 0;
  while (a[count] != NULL)
    count++;
  
  count++;			

  int **tail[K];
  for (int k = 0; k < K; k ++) {
    head[k] = NULL;
    tail[k] = NULL;
  }

  for (int i = 0; i < count; i++) {
    int k = A[i] % K;
    if (head[k] == NULL) {
      head[k] = &(A[i]);
      tail[k] = &(a[i]);
    } else {
      (*(tail[k])) = &(A[i]);
      tail[k] = &(a[i]);
    }
  }

  for (int k = 0; k < K; k++)
    if (tail[k] != NULL)
      (*(tail[k])) = NULL;
  
}

