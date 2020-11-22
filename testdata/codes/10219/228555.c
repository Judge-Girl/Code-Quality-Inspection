int findSize(int *array[]) {
        int ret = 1;
        for (int i = 0; array[i]; i++)
                ret++;
        return ret;
}
void merge(int A[], int B[], int* a[], int* b[]) {
    int nA = findSize(a), nB = findSize(b);
    int va = 0, vb = 0;
    while (va != nA && vb != nB) {
            if (A[va] < B[vb]) {
                    if (va == nA - 1 || B[vb] < A[va + 1])
                            a[va] = &B[vb];
                    else
                            a[va] = &A[va + 1];
                    va++;
            }
            else {
                    if ( vb == nB - 1 || A[va] < B[vb + 1])
                            b[vb] = &A[va];
                    else
                            b[vb] = &B[vb + 1];
                    vb++;
            }
    }
    if (va == nA)
            while (vb < nB - 1) {
                    b[vb] = &B[vb + 1];
                    vb++;
            }
    else
            while (va < nA - 1) {
                    a[va] = &A[va + 1];
                    va++;
            }
}
