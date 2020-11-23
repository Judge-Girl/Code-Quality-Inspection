void merge0(int a[], int b[], int *pa[], int *pb[], int **cur) {
	if (*a < *b) {
		if (cur) *cur = a;
		if (pa[0]) merge0(a + 1, b, pa + 1, pb, pa);
		else pa[0] = b;
	} else {
		if (cur) *cur = b;
		if (pb[0]) merge0(a, b + 1, pa, pb + 1, pb);
		else pb[0] = a;
	}
}

void merge(int a[], int b[], int *pa[], int *pb[]) { merge0(a, b, pa, pb, 0); }
