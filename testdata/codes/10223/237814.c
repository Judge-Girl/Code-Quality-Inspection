#include <stdio.h>
#include <string.h>
int main()
{
	char s[10001];
	int i, j;
	while(~scanf("%s%d%d", s, &i, &j))
	{
		char vowels[] = "aeiou";
		char ansi[10001], ansj[10001];
		int len = strlen(s);
		char r[10001];
		strcpy(r, s);
		int start, anslen;
		start = 0;
		for(int x = 0; x <= i; x++)
		{
			anslen = strcspn(s + start, vowels);
			strncpy(ansi, s + start, anslen);
			ansi[anslen] = s[anslen + start];
			ansi[anslen+1] = '\0';
			// printf("%s\n", ansi);
			if(x != i)
				start += anslen + 1;
		}


		for(int x = 0; x < start ; x++)
			printf("+");
		printf("%s", ansi);
		for(int x = 0; x < len - anslen - start - 1; x++)
			printf("+");
		printf("\n");
		for(int x = start; x < start + anslen + 1; x++)
		{
			r[x] = '+';
		}
		// printf("%s\n", r);

		start = 0;
		for(int x = 0; x <= j; x++)
		{
			anslen = strcspn(s + start, vowels);
			strncpy(ansj, s + start, anslen);
			ansj[anslen] = s[anslen + start];
			ansj[anslen+1] = '\0';
			// printf("%s\n", ansj);
			if(x != j)
				start += anslen + 1;
		}


		for(int x = 0; x < start ; x++)
			printf("+");
		printf("%s", ansj);
		for(int x = 0; x < len - anslen - start - 1; x++)
			printf("+");
		for(int x = start; x < start + anslen + 1; x++)
		{
			r[x] = '+';
		}
		printf("\n");
		printf("%s\n", r);
	}
	return 0;
}
