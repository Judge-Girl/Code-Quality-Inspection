#include"stdio.h"
#include"string.h"

union obj
{
	long long n;
	char str[8];
};

int main()
{
	int t;
	scanf("%d",&t);
	union obj tmp;
	if(t)
	{
		int n;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%lld",&tmp.n);
			int i=8;
			while(i--&&tmp.str[i])
				putchar_unlocked(tmp.str[i]);
		}
		putchar_unlocked('\n');
	}
	else
	{
		char c=getchar_unlocked();
		int i=8;
		for(;;)
		{
			c=getchar();
			c=(c==10?0:c);
			tmp.str[--i]=c;
			if(i==0)
				printf("%lld\n",tmp.n),i=8;
			if(!c)
				break;
		}
		if(i<8)
		{
			memset(tmp.str,0,i);
			printf("%lld\n",tmp.n);
		}
	}
}
