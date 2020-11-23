void split(int A[], int *a[], int *head[], int k)
{
	int n=0;
	while(a[n++]);
	while(n--)
		a[n]=head[A[n]%k],head[A[n]%k]=&A[n];
}
