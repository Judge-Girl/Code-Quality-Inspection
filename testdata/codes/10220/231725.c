int pos[1024 * 1024][2];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
  int r, c;
  for (r = 0; r < N; r++) {
    for (c = 0; c < N; c++) {
      pos[A[r][c]][0] = r;
      pos[A[r][c]][1] = c;
    }
  }
  for (r = 0; r < N; r++) {
    for (c = 0; c < N; c++) {
    int next, nextr, nextc;
      if (A[r][c] == N * N - 1) {
        next = 0;
        nextr = pos[next][0];
        nextc = pos[next][1];
      } else {
        next = A[r][c] + 1;
        nextr = pos[next][0];
        nextc = pos[next][1];
      }
      B[r][c] = &(A[nextr][nextc]);
    }
  }
  return;
}

