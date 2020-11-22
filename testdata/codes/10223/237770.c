#include<stdio.h>
#include<string.h>

int main()
{	
	char A[10001];
	int i,j,k,vowel,start_i,start_j,end_i,end_j,in_i,in_j,tmp;

	memset(A,'\0',10001);
	while(scanf("%s",A)!=EOF)
	{
		scanf("%d%d",&i,&j);

		k=0;
		vowel=-1;
		in_i=0;
		in_j=0;
		tmp=-1;
		while(A[k]!='\0')
		{
			if(A[k]=='a' || A[k]=='e' || A[k]=='i' || A[k]=='o' || A[k]=='u')
			{
				vowel++;
				if(vowel==i)
				{
					end_i=k;
					start_i=tmp+1;
				}
				if(vowel==j)
				{
					end_j=k;
					start_j=tmp+1;
				}
				tmp=k;
			}
			k++;
		}
		

		k=0;
		while(A[k]!='\0')
		{
			if(k>=start_i && k<=end_i)
			{
				printf("%c",A[k]);
			}
			else
			{
				printf("%c",'+');
			}
			k++;
		}
		printf("\n");

		k=0;
		while(A[k]!='\0')
		{
			if(k>=start_j && k<=end_j)
			{
				printf("%c",A[k]);
			}
			else
			{
				printf("%c",'+');
			}
			k++;
		}
		printf("\n");

		k=0;
		while(A[k]!='\0')
		{
			if((k>=start_j && k<=end_j) || (k>=start_i && k<=end_i))
			{
				printf("%c",'+');
			}
			else
			{
				printf("%c",A[k]);
			}
			k++;
		}
		printf("\n");
	}

	return 0;
}
