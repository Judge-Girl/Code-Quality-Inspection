#include<stdio.h>

int main()
{
	int T,i,j,N;
	char str[100003];
	long long int S,temp;

	scanf("%d",&T);

	if(T==0)
	{
		scanf("%s",str);
		i=0;
		S=0;
		j=0;
		while(str[i]!='\0')
		{
			S=S|(int)str[i];
			j++;
			if(j==8)
			{
				printf("%lld\n",S);
				S=0;
				j=0;
			}
			S=S<<8;
			i++;
		}
		if((j+1)<8)
		{
			S=S<<8*(8-(j+1));
		}
		printf("%lld\n",S);
	}
	else
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			S=0;
			scanf("%lld",&temp);
			for(j=1;j<8;j++)
			{
				S=S|(temp&255);
				temp=temp>>8;
				S=S<<8;
			}
			S=S|(temp&255);
			for(j=1;j<9;j++)
			{
				if((S&255)>0)
				{
					printf("%c",S&255);
				}
				S=S>>8;
			}
		}

	}

	return 0;
}
