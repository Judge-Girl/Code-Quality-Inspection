#include<stdio.h>
#include<string.h>

int main()
{
	char s[3][11000],v[]="aeiou";
	int a[2],t,i;
	char *c,*l;
	while(memset(s,'+',33000),~scanf("%s%d%d",s[2],a,a+1))
	{
		for(t=0,l=c=s[2];*c;c++)
		{
			if(strchr(v,*c))
			{
				i=2;
				for(;i--;)
					if(t==a[i])
						memcpy(l-11000*(2-i),l,c-l+1),memset(l,'+',c-l+1);
				++t;
				l=c+1;
			}
		}
		*(c-11000)=*(c-22000)=0;
		printf("%s\n%s\n%s\n",s[0],s[1],s[2]);
	}
}
