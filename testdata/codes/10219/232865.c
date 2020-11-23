#include <stdio.h> 
void merge(int A[], int B[], int* a[], int* b[])
{
  int indexA = 0, indexB = 0;
  int **last = NULL;
  int lastOn;

  do {
    if (A[indexA] < B[indexB]) {
      if (last == NULL)
	last = &(a[indexA]);
      else {
	(*last) = &(A[indexA]);
	last = &(a[indexA]);
      }
      lastOn = 0;
#ifdef DEBUG
      printf("add %d\n", A[indexA]);
#endif
      indexA++;
    } else {
      if (last == NULL)
	last = &(b[indexB]);
      else {
	(*last) = &(B[indexB]);
	last = &(b[indexB]);
      }
      lastOn = 1;
#ifdef DEBUG
      printf("add %d\n", B[indexB]);
#endif
      indexB++;
    }
  } while (*last != NULL);

  if (lastOn == 1) {
#ifdef DEBUG
    printf("add starting %d\n", A[indexA]);
#endif
    *last = &(A[indexA]);
  } else {
    *last = &(B[indexB]);
#ifdef DEBUG
    printf("add starting %d\n", B[indexB]);
#endif
  }
}

