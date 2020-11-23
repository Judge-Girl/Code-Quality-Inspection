#include"stdio.h"
#include"string.h"

int main()
{
	int t;
	scanf("%d",&t);
	char str[8];
	long long p;
	if(t)
	{
		int n;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%lld",&p);
			memcpy(str,&p,8);
			int i=8;
			while(i--&&str[i])
				putchar_unlocked(str[i]);
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
			str[--i]=c;
			if(i==0)
				memcpy(&p,str,8),printf("%lld\n",p),i=8;
			if(!c)
				break;
		}
		if(i<8)
		{
			memset(str,0,i);
			memcpy(&p,str,8);
			printf("%lld\n",p);
		}
	}
}
