//10219. Line Up Numbers

#include <stdio.h> 
void merge(int A[], int B[], int* a[], int* b[])
{
	int Anum = 0, Bnum = 0;
	while(a[Anum] != NULL){
		Anum++;
	}
	while(b[Bnum] != NULL){
		Bnum++;
	}
	int apos = 0, bpos = 0;
	while(apos <= Anum && bpos <= Bnum){
#ifdef DEBUG
		printf("A[%d] %d B[%d] %d\n", apos, A[apos], bpos, B[bpos]);
#endif
		if(apos<Anum && bpos<Bnum){
			if(A[apos]<B[bpos] && B[bpos]<A[apos+1]){
				a[apos] = &B[bpos];
				apos++;
			}
			else if(A[apos]<B[bpos] && B[bpos]>A[apos+1]){
				a[apos] = &A[apos+1];
				apos++;
			}
			else if(A[apos]>B[bpos] && B[bpos+1]>A[apos]){
				b[bpos] = &A[apos];
				bpos++;
			}
			else if(A[apos]>B[bpos] && B[bpos+1]<A[apos]){
				b[bpos] = &B[bpos+1];
				bpos++;
			}
		}
		else if(apos<Anum && bpos==Bnum){
			if(A[apos]<B[bpos] && B[bpos]<A[apos+1]){
				a[apos] = &B[bpos];
				apos++;
			}
			else if(A[apos]<B[bpos] && B[bpos]>A[apos+1]){
				a[apos] = &A[apos+1];
				apos++;
			}
			else if(A[apos]>B[bpos]){
				b[bpos] = &A[apos];
				bpos++;
			}
		}
		else if(apos==Anum && bpos<Bnum){
			if(A[apos]<B[bpos]){
				a[apos] = &B[bpos];
				apos++;
			}
			else if(A[apos]>B[bpos] && B[bpos+1]>A[apos]){
				b[bpos] = &A[apos];
				bpos++;
			}
			else if(A[apos]>B[bpos] && B[bpos+1]<A[apos]){
				b[bpos] = &B[bpos+1];
				bpos++;
			}
		}
		else{
			if(A[apos]<B[bpos]){
				a[apos] = &B[bpos];
				apos++;
			}
			else{
				b[bpos] = &A[apos];
				bpos++;
			}
		}
	}
	 
	

#ifdef DEBUG
	printf("apos %d bpos %d\n", apos, bpos);
	printf("Anum %d Bnum %d\n", Anum, Bnum);
	printf("a ");
	for(int i = 0 ; i < Anum ; i++){
		printf("%d ", *a[i]);
	}
	printf("\n");
	printf("b ");
	for(int i = 0 ; i < Bnum ; i++){
		printf("%d ", *b[i]);
	}
#endif
}
