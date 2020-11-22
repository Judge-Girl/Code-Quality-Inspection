#include<stdio.h> 
const int *add[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
  int i,j,k,x;
  
for(i=0;i<N;i++)
    {
       for(j=0;j<N;j++)
		{
		add[A[i][j]]=&A[i][j];
		}
		
	}	

	for(i=0;i<N;i++)
  	  {
		for(j=0;j<N;j++)
		  {
		  	if(A[i][j]==N*N-1)
		  	  {
			   B[i][j]=add[0];
			   continue;
			  }
			B[i][j]=add[A[i][j]+1] ;
		  }
	  }
} 


