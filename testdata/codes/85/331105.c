#include <stdio.h>
#include <stdlib.h>



int A[1000000] = {};

int cmp(const void* a, const void* b) {
  return *(int*) a - *(int*) b;
}

int main() {
  int cnt, year, month, day;
  scanf("%d", &cnt);
  for(int i = 0; i < cnt; i++) {
    scanf("%d%d%d", &year, &month, &day);
    A[i] = year * 416 + month * 32 + day;
  }
  qsort(A, cnt, sizeof(int), cmp);
  for(int i = 0; i < cnt; i++) {
    printf("%d %d %d\n", A[i] / 416, A[i] % 416 / 32, A[i] % 32);
  }
}

