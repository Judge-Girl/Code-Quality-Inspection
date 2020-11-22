#include <stdio.h> 
void merge(int A[], int B[], int* a[], int* b[]){
	int cntA = 0, cntB = 0, indexa = 0, indexb = 0, prev, amountA = 1, amountB = 1, i; // prev = 1 for A, 2 for B
	for(i = 1; a[i - 1] != NULL; i++){
		amountA = i + 1;
	}
	for(i = 1; b[i - 1] != NULL; i++){
		amountB = i + 1;
	}
	if(A[0] < B[0]){
		cntA++;
		amountA--;
		prev = 1;
	}
	else{
		cntB++;
		amountB--;
		prev = 2;
	}
	while(amountA > 0 || amountB > 0){
		if(amountA > 0 && amountB > 0){
			if(A[cntA] < B[cntB]){
				if(prev == 1){
					a[indexa] = &(A[cntA]);
					indexa++;
				}
				else{
					b[indexb] = &(A[cntA]);
					indexb++;
				}
				amountA--;
				prev = 1;
				cntA++;
			}
			else{
				if(prev == 1){
					a[indexa] = &(B[cntB]);
					indexa++;
				}
				else{
					b[indexb] = &(B[cntB]);
					indexb++;
				}
				amountB--;
				prev = 2;
				cntB++;
			}
		}
		else if(amountA == 0 && amountB > 0){
			if(prev == 1){
				a[indexa] = &(B[cntB]);
				indexa++;
			}
			else{
				b[indexb] = &(B[cntB]);
				indexb++;
			}
			amountB--;
			cntB++;
			prev = 2;
		}
		else if(amountB == 0 && amountA > 0){
			if(prev == 1){
				a[indexa] = &(A[cntA]);
				indexa++;
			}
			else{
				b[indexb] = &(A[cntA]);
				indexb++;
			}
			amountA--;
			cntA++;
			prev = 1;
		}
	}
	return;
}
/*int main()
{
    int A[10], B[10];
    int *a[10], *b[10], *ans_a[10], *ans_b[10];
    int i, N, M;
 
    scanf("%d%d", &N, &M);
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(i = 0; i < M; i++)
        scanf("%d", &B[i]);
    for(i = 0; i < N-1; i++)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for(i = 0; i < M-1; i++)
        b[i] = &B[i+1];
    b[M-1] = NULL;
 
    merge(A, B, a, b);
 
    ans_a[0] = &B[0]; ans_a[1] = &A[2]; ans_a[2] = &B[1]; ans_a[3] = &B[2];
    ans_b[0] = &A[1]; ans_b[1] = &A[3]; ans_b[2] = NULL;
 
    for(i = 0; i < N; i++){
        if(a[i] != ans_a[i])
            printf("a[%d] is Wrong!\n", i);
    }
    for(i = 0; i < M; i++){
        if(b[i] != ans_b[i])
            printf("b[%d] is Wrong!\n", i);
    }
    printf("Finish!\n");
    return 0;
}
*/
