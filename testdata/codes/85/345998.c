#include <stdio.h>
#include <stdlib.h>

#define debug

#define N 1000000

#ifdef debug
typedef struct date {
    int year;
    char month;
    char day;
} Date;

Date t[N];

int compare(const void *s1, const void *s2)
{
    Date *p1 = (Date *)s1;
    Date *p2 = (Date *)s2;
    if (p1->year > p2->year) return 1;
    if (p1->year < p2->year) return -1;
    if (p1->month > p2->month) return 1;
    if (p1->month < p2->month) return -1;
    if (p1->day > p2->day) return 1;
    if (p1->day < p2->day) return -1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &t[i].year, &t[i].month, &t[i].day);
    }
    qsort(t, n, sizeof(Date), compare);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", t[i].year, t[i].month, t[i].day);
    }
    return 0;
}
#endif // debug

#ifdef answer

typedef struct {
	int y, m, d;
} Date;

Date D[1000000];
int cmp(const void *x, const void *y) {
	Date *a = (Date*) x;
	Date *b = (Date*) y;
	if (a->y < b->y)	return -1;
	if (a->y > b->y)	return 1;
	if (a->m < b->m)	return -1;
	if (a->m > b->m)	return 1;
	if (a->d < b->d)	return -1;
	if (a->d > b->d)	return 1;
	return 0;
}
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++)
			scanf("%d %d %d", &D[i].y, &D[i].m, &D[i].d);
		qsort(D, n, sizeof(Date), cmp);
		for (int i = 0; i < n; i++)
			printf("%d %d %d\n", D[i].y, D[i].m, D[i].d);
	}
	return 0;
}
#endif // answer

