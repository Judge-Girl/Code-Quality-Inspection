#include <stdio.h>
#include <stdlib.h>
 
struct Date {
    int y, m, d;
};

int cmp(const void *x, const void *y) { //any positive is same as 1, any negative is same as -1
    const struct Date *a = (const struct Date*) x;
    const struct Date *b = (const struct Date*) y;
    if((int)(a->y - b->y) == 0) {
        if((int)(a->m - b->m) == 0) {
            return (int)(a->d - b->d);
        }
        return (int)(a->m - b->m);
    }
    return (int)(a->y - b->y);
}

int main(void) {
    int n;
    scanf("%d", &n);
    struct Date *D = (struct Date *)malloc(sizeof(struct Date)*n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &D[i].y, &D[i].m, &D[i].d);
    qsort(D, n, sizeof(struct Date), cmp);
    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", D[i].y, D[i].m, D[i].d);
    return 0;
}
