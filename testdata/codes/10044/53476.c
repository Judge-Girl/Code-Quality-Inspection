#include <stdio.h>
int max=0, N, arr[100][100], chosen[100];
void find(int k, int valid[], int n) {
	if(k>max) max=k;
	if(k+n<=max||!n) return;
	chosen[k]=valid[0];
	int _valid[100];
	int tmp=0;
	for (int i=0; i<n; i++) {
		if(arr[valid[0]][valid[i]])
			_valid[tmp++]=valid[i];
	}
	find(k+1, _valid, tmp);
	find(k, valid+1, n-1);
}
int main(void) {
	int valid[100];
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		valid[i]=i;
		for (int j=0; j<N; j++) 
			scanf("%d", &arr[i][j]);
	}
	find(0, valid, N);
	printf("%d\n", max);
}
