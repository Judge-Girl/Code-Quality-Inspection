#include<stdio.h>
int main()
{
int N,a,b,x,y,k;
int X[100000],Y[100000];
scanf("%d",&N);
a=0;
while(a<2*N)
	{
	 scanf("%d%d",&X[a],&Y[a]);
	 a++;
	}
a=1;
while(a<2*N)
	{
	 if(a%2==1) b=0;
	 if(a%2==0) b=1;
	 k=70000;
	 while(b<a)
		{
		 x=X[a]-X[b];
		 y=Y[a]-Y[b];
		 if(x<0) x=-x;
		 if(y<0) y=-y;
		 if(k>x+y) k=x+y;
		 b=b+2;
		}
	 printf("%d\n",k);
	 b=0;
	 a++;
	}
return 0;
}

