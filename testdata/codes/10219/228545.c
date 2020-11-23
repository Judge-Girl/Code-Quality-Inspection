void merge0(int a[], int b[], int *pa[], int *pb[], int **cur) {
	int *p1 = a, *p2 = b, **pp1 = pa, **pp2 = pb, *pt, **ppt;
	if (*a > *b) pt = p1, p1 = p2, p2 = pt, ppt = pp1, pp1 = pp2, pp2 = ppt;
	if (cur) *cur = p1;
	if (*pp1) merge0(p1 + 1, p2, pp1 + 1, pp2, pp1);
	else *pp1 = p2;
}

void merge(int a[], int b[], int *pa[], int *pb[]) { merge0(a, b, pa, pb, 0); }
