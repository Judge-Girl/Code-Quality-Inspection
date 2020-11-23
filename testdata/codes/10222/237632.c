#include <stdio.h>

void split(int A[], int *a[], int *head[], int K)
{
  int **tail[K];
  for (int k = 0; k < K; k++) {
    head[k] = NULL;
    tail[k] = NULL;
  }

  int index = 0;
  do {
    int k = A[index] % K;
    if (head[k] == NULL) 
      head[k] = &(A[index]);
    else 
      (*(tail[k])) = &(A[index]);
    tail[k] = &(a[index]);
  } while (a[index++] != NULL);

  for (int k = 0; k < K; k++)
    if (tail[k] != NULL)
      (*(tail[k])) = NULL;
  
}

