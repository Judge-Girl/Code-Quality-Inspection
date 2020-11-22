#include <stdio.h>
#include <string.h>
char Word[10000];int one;int two;int count = 0;int Mark[10000];int len;
int main()
{
	while(scanf("%s%d%d", Word, &one, &two) != EOF){
		count = 0;
		len = strlen(Word);
	for(int i = 0; i < len; i++)
	{
		Mark[i] = 0;
		if(Word[i] == 'a'||Word[i] == 'e'||Word[i] == 'i'||Word[i] == 'o'||Word[i] == 'u')
		{
			Mark[count++] = i;
		}
	}
	int start = 0;
	
	for(int i = 0; i < len; i++)
	{
		if(one != 0)
		if(i == Mark[one-1])
		{
			printf("+");
			start = 1;
			continue;
		}
		if(i ==  Mark[one])
		{
			printf("%c", Word[i]);
			start = 0;
			continue;
		}

		if(one == 0&&i == 0)start = 1;
		if(start) printf("%c", Word[i]);
		else printf("+");
	}
	printf("\n");
	start = 0;
	for(int i = 0; i < len; i++)
	{
		if(two != 0)
		if(i == Mark[two-1])
		{
			printf("+");
			start = 1;
			continue;
		}
		if(i ==  Mark[two])
		{
			printf("%c", Word[i]);
			start = 0;
			continue;
		}

		if(two == 0&&i == 0)start = 1;	
		if(start) printf("%c", Word[i]);
		else printf("+");
	}

	printf("\n");
	start = 0;
	for(int i = 0; i < len; i++)
	{
		if((one == 0||two == 0)&&i==0)start = 1;

		if(two != 0)
		if(i == Mark[two-1])
		{
			if(i != Mark[one])
				printf("%c", Word[i]);
			else
				printf("+");
			start = 1;
			
			continue;
		}
		if(one != 0)
		if(i == Mark[one-1])
		{
			if(i != Mark[two])
				printf("%c", Word[i]);
			else
				printf("+");
			start = 1;
			
			continue;
		}

		if(i ==  Mark[two])
		{
			printf("+");
			start = 0;
			continue;
		}
		if(i ==  Mark[one])
		{
			printf("+");
			start = 0;
			continue;
		}
		if(start)printf("+");
		else printf("%c", Word[i]);
	}
	printf("\n");
}
}
