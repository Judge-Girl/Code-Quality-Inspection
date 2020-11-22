#include <stdio.h>
#include <stdlib.h>
int store[1000000] = {0};
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int main() {
    int dN;
    int y, m, d;
    scanf("%d", &dN);
    for (int i = 0; i < dN; i ++) {
        scanf("%d%d%d", &y, &m, &d);
        store[i] |= (y << 9) | (m << 5) | d;
    }
    qsort(store, dN, sizeof(int), cmp);
    for (int i = 0; i < dN; i ++)
        printf("%d %d %d\n", store[i] >> 9, (store[i] >> 5) & 15, store[i] & 31);
    return 0;
}
