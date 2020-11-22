#include <stdio.h>
#include <stdlib.h>

int cmp(const void *x, const void *y) {
	return *(int *) x - *(int *) y;
}

int main() {
	int n, a[1000005];
	scanf("%d", &n);

	int y, m, d;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &y, &m, &d);
		int Hash = 0;
		Hash += y, Hash <<= 4, Hash += m, Hash <<= 5, Hash += d;
		a[i] = Hash;
	}
	qsort(a, n, sizeof(int), cmp);
	for (int i = 0; i < n; ++i)
		printf("%d %d %d\n", a[i]>>9, (a[i]>>5) & 15, a[i] & 31);
	return 0;
}

