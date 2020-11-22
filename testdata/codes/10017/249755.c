#include <stdio.h>
#include <limits.h>

int Abs(int x) {
  return x >= 0 ? x : (-x);
}

int is[2][50005], js[2][50005];
int main() {
  int n;
  scanf("%d", &n);
  n *= 2;
  for (int cur = 0; cur < n; ++cur) {
    scanf("%d%d", &is[cur % 2][cur / 2], &js[cur % 2][cur / 2]);
    int min = INT_MAX;
    for (int k = 1 - (cur % 2); k < cur; k += 2) {
      int dist = Abs(is[cur % 2][cur / 2] - is[k % 2][k / 2]) + Abs(js[cur % 2][cur / 2] - js[k % 2][k / 2]);
      if (dist < min) min = dist;
    }
    if (min != INT_MAX) printf("%d\n", min);
  }
}


