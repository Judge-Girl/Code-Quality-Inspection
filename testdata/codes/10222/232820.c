#include <stdio.h>
#include <stdlib.h>
//#include "split.h"

int tail[100000];

void split(int A[], int *a[], int *head[], int k)
{
	//calculate A size
	int aSize = 1;
	for (int i = 0; a[i] != NULL; i++) {
		aSize++;
	}

    for (int i = 0; i < aSize; i++) {
        a[i] = NULL;
    }


	// printf("Size of A is %d\n", aSize);

	for (int i = 0; i < aSize; i++) {
        int fish = A[i] % k;
        if (head[fish] == NULL) {
            head[fish] = &A[i];
            tail[fish] = i;
        } else {
            a[tail[fish]] = &A[i];
            tail[fish] = i;
        }
    }

    // for (int i = 0; i < k; i++) {
    //     a[tail[i]] = NULL;
    // }

    return;

}
