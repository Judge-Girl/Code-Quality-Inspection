//10222. split.c
#include <stdio.h> //for NULL

//method 2:
void split(int A[], int *a[], int *head[], int k)
{
	//Method 2
	//O(k*N) is too slow!!
	//get number of A[]
	int n = 0;
	while(a[n] != NULL)
	{
		n++;
	}
	n++; 
	//now n is number of A[]
	int tail[k];
	for(int re=0;re<k;re++)
	{
		tail[re] = (-1);
	}
	int firstHead[k];
	for(int re=0;re<k;re++)
	{
		firstHead[re] = 1;
	}
	for(int i=0;i<n;i++)
	{
		int re = A[i]%k; //remainder of A[i]
		//handle head if firstHead == 1
		if(firstHead[re] == 1 )
		{
			firstHead[re] = 0; //
			head[re] = &A[i];
			tail[re] = i;
			continue;
		}
		else //handle rest element if firstHead = 0
		{
			a[ tail[re] ] = &A[i]; //old point to new
			tail[re] = i; //change current tail to i
			continue;
		}
	} //End go through all A[]

	//
	for(int re=0;re<k;re++)
	{
		if(tail[re] != (-1) )
		{
			a[ tail[re] ] = NULL;
		}
	}

	//if not found this remainder class in A[]
	for(int re=0;re<k;re++)
	{
		if( firstHead[re] == 1 )
		{ //not found this remainder class in A[]
			head[re] = NULL;
		}
	}
	

	//Method 1
	/*
	//get number of A[]
	int n = 0;
	while(a[n] != NULL)
	{
		n++;
	}
	n++; //now n is number of A[]
	//
	//int tail[k] = {0}; //Init.
	//
	for(int re=0;re<k;re++) //for remainder = 0~(k-1)
	{
		//first handle head[]:
		int tail = 0; //reset for each remainder class
		//find that remainder class
		int notFoundRemainder = 1;
		for(int i=0;i<n ;i++)
		{
			if(re == A[i]%k )
			{
				notFoundRemainder = 0;
				head[re] = &A[i];
				tail = i;
				break; //found head of this remainder
			}
		}
		if(notFoundRemainder == 1)
		{
			head[re] = NULL;
			continue; //to next remainder class
		}

		//now other elements 
		for(int i=tail+1;i<n;i++)
		{
			if(re == A[i]%k)
			{
				a[tail] = &A[i]; //old point to new
				tail = i; //change current tail to i
			}
		}
		//finally set last element of this remainder list pointing to NULL
		a[tail] = NULL;
		//if tail+1>n-1, then must set NULL
	} //End all remainders
	*/
}
 

