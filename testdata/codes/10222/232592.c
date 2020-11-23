#include "split.h"
#include <stdlib.h>
#include <stdio.h>

void split(int A[], int *a[], int *head[], int k) {
	int tail[100000] = {0};
	for (int j = 0; j < k; ++j) {
		head[j] = NULL;
	}
	int i = 0;
	while (1) {
		int group = A[i]%k;
		if (head[group] == NULL) {
			head[group] = &A[i];
			tail[group] = i;
		}
		else {
			a[tail[group]] = &A[i];
			tail[group] = i;
		}
		if (a[i] == NULL) break;
		++i;
	}
	for (int i = 0; i < k; ++i) {
		if (head[i] != NULL)
			a[tail[i]] = NULL;
	}
}



