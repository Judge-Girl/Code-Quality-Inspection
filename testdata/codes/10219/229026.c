#include <stdio.h> 
void merge(int A[], int B[], int* a[], int* b[])
{
	int Acount=0,Bcount=0,**start,stopA=0,stopB=0;
	if(A[0]<B[0])
		{
			Acount++;
		  	start=&a[0];
		  	
		}
	else
		{
			Bcount++;
			start=&b[0];
		}
	if(a[0]==NULL&&A[0]<B[0])
	stopA=1;
	if(b[0]==NULL&&A[0]>B[0])
	stopB=1;
	if(stopA+stopB==2)
	{
		if(A[0]<B[0])
		{
		  	*start=&B[0];
		}
	else
		{
			*start=&A[0];
		}
	}
	while(stopA==0||stopB==0)
	{
		if(stopA==0&&(A[Acount]<B[Bcount]||stopB==1))
			{
			*start=&A[Acount];
			start=&a[Acount];
			if(a[Acount]==NULL)
				stopA++;
			Acount++;
			}
		if(stopB==0&&(A[Acount]>B[Bcount]||stopA==1))
			{
			*start=&B[Bcount];
			start=&b[Bcount];
			if(b[Bcount]==NULL)
				stopB++;
			Bcount++;
			}
	}
}

