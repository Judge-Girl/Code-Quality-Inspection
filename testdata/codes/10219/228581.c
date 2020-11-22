int **cur = 0;
void merge(int a[], int b[], int *pa[], int *pb[]) {
	int *p[] = { a, b }, **pp[] = { pa, pb }, i = *a > *b;
	if (cur) *cur = p[i];
	cur = pp[i];
	if (*pp[i]) merge(p[i] + 1, p[!i], pp[i] + 1, pp[!i]);
	else *pp[i] = p[!i];
}
