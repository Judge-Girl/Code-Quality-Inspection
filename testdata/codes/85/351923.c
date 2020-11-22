#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int sscan() {
  register int n = 0, c = getchar_unlocked();
  while(c < '0'|| c > '9')
    c = getchar_unlocked();
  while(c <= '9' && c >= '0') {
    n = n * 10 + c - '0';
    c = getchar_unlocked();
  }
  return n;
}

typedef struct {
  int y, m, d;
} date;

date D[MAX];

int cmp (const void *A, const void *B) {
  date *a = (date *) A;
  date *b = (date *) B;

  if(a->y != b->y)
    return (a->y - b->y);
  if(a->m != b->m)
    return (a->m - b->m);
  if(a->d != b->d)
    return (a->d - b->d);

  return 0;
}

int main () {
  int n;
  n = sscan();

  for(int i = 0; i < n; i++) {
    D[i].y = sscan();
    D[i].m = sscan();
    D[i].d = sscan();
  }

  qsort(D, n, sizeof(date), cmp);

  for(int i = 0; i < n; i++)
    printf("%d %d %d\n", D[i].y, D[i].m, D[i].d);
}

