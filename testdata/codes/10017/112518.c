#include <stdio.h>
#include <stdlib.h>
#define dist(x1,y1,x2,y2)  ( abs((x1) - (x2)) + abs((y1) - (y2)) )

// TODO: maintain a heap or something efficient!!!!!!

static int listA[50032][2];
static int listB[50032][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int mind;

    scanf("%d%d", &listA[i][0], &listA[i][1]);
    mind = 1 << 20;
    for (int j = 0; j <= i - 1; j++) {
      int d = dist(listA[i][0], listA[i][1], listB[j][0], listB[j][1]);
      if (d < mind) mind = d;
    }
    if (i != 0) printf("%d\n", mind);

    scanf("%d%d", &listB[i][0], &listB[i][1]);
    mind = 1 << 20;
    for (int j = 0; j <= i; j++) {
        int d = dist(listB[i][0], listB[i][1], listA[j][0], listA[j][1]);
        if (d < mind) mind = d;
      }
    printf("%d\n", mind);
  }
}

