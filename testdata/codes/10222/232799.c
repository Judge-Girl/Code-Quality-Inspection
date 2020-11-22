#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tmp, tail[100001][100], index[100001]={0};
void split(int A[], int *a[], int *head[], int k)
{
	int i=0, j, num_A;
	while(1){
        if(a[i] != NULL)
            i++;
        else{
            num_A = i+1;
            break;
        }
    }
	if(k == 1){
		head[0] = &A[0];
		for(i=1; i<num_A; i++){
			a[i-1] = &A[i];
		}
	}
	else{
		for(i=0; i<num_A; i++){
			tmp = A[i]%k;
			tail[tmp][index[tmp]] = i;
			index[tmp] ++;
			if(head[tmp] == NULL)
				head[tmp] = &A[i];
		}
		for(i=0; i<k; i++){
			for(j=0; j<index[i]-1; j++)
				a[tail[i][j]] = &A[tail[i][j+1]];
			if(index[i] != 0)
				a[tail[i][index[i]-1]] = NULL;
			else if(index[i] == 0)
				head[i] = NULL;
		}
	}
}
