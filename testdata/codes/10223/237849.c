#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char input[20000];
	char *syl[20000];
	char vowel[5]="aeiou";\
	char out1[20000];
	char out2[20000];
	char out3[20000];
	int imp1,imp2,n,x=0,y;
	char *start;
	int syllen[20000];
	
	while(scanf("%s",input)!=EOF)
	{

		start = input;
		scanf("%d",&imp1);
		scanf("%d",&imp2);
		x=0;
		for(n=0;n>=0;n++)
		{
		
			if(start+strcspn(start,vowel)-input>=strlen(input))
			break;
			syl[n]=start;
			syllen[n]=strcspn(start,vowel)+1;
			start+=strcspn(start,vowel);
			start++;
			if(n==imp1)
			{
				for(y=0;y<syllen[n];y++)
				{
					out1[x+y]=input[x+y];
					out2[x+y]='+';
					out3[x+y]='+';
				}
				x+=syllen[n];
			}
			else if(n==imp2)
			{
				for(y=0;y<syllen[n];y++)
				{
					out1[x+y]='+';
					out2[x+y]=input[x+y];
					out3[x+y]='+';
				}
				x+=syllen[n];
			}
			else
			{
				for(y=0;y<syllen[n];y++)
				{
					out1[x+y]='+';
					out2[x+y]='+';
					out3[x+y]=input[x+y];
				}
				x+=syllen[n];
			}
		}
		while(x<strlen(input))
		{
			out1[x]='+';
			out2[x]='+';
			out3[x]=input[x];
			x++;
		}
		out1[x]='\0';
			out2[x]='\0';
				out3[x]='\0';
	printf("%s\n",out1);
	printf("%s\n",out2);
	printf("%s\n",out3);
	}
	return 0;
}
