#include "constructPointerArray.h"

#include <stdio.h>

const int *pos[MAXN * MAXN];

void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N) {
  const int TOTAL = N * N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      pos[A[i][j]] = &A[i][j]; 
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      B[i][j] = pos[(A[i][j] + 1) % TOTAL];
    } 
  }
}

