#include <stdio.h>
#include <string.h>

int isMother(char c)  {
	if (c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u')
		return 1;
	else
		return 0;
}

int main(int argc, char const *argv[])
{
	char word[10001];
	int i, j;
	char one[10001];
	char two[10001];
	char three[10001];
	int map[10001];
	int order[10001];
	for (int k = 0; k < 10001; k++) {
		map[k] = -1;
		one[k] = '+';
		two[k] = '+';
		three[k] = '+';
	}


	while (scanf("%s", word) != EOF)  {
		for (int k = 0; k < 10001; k++) {
			map[k] = -1;
			one[k] = '+';
			two[k] = '+';
			three[k] = '+';
		}
		scanf("%d%d", &i,&j);
		int len = strlen(word);
		int count = 0;
		for (int index = 0; index < len; index++)
		{
			if (isMother(word[index]) == 1)  {
				map[index] = count;
				order[count] = index;
				count++;
			}
		}
		if (i == 0)
		{
			for (int index = 0; index <= order[i]; index++)
			{
				one[index] = word[index];
			}
			one[len] = '\0';
		}

		if (i != 0)
		{
			for (int index = order[i-1]+1; index <= order[i]; index++)
			{
				one[index] = word[index];
			}
			one[len] = '\0';
		}
		if (j == 0)  {
			for (int index = 0; index <= order[j]; index++)
			{
				two[index] = word[index];
			}
			two[len] = '\0';
		}
		if (j != 0)  {
			for (int index = order[j-1]+1; index <= order[j]; index++)
			{
				two[index] = word[index];
			}
			two[len] = '\0';
		}
		if (i != 0 && j != 0)  {
			for (int index = 0; index < len; index++)
			{
				if (index >= order[j-1]+1 && index <= order[j]) continue;
				if (index >= order[i-1]+1 && index <= order[i]) continue;
				three[index] = word[index];
			}
			three[len] = '\0';
		}
		if (i == 0)
		{
			for (int index = 0; index < len; index++)
			{
				if (index >= order[j-1]+1 && index <= order[j]) continue;
				if (index <= order[i]) continue;
				three[index] = word[index];
			}
			three[len] = '\0';
		}
		if (j == 0)
		{
			for (int index = 0; index < len; index++)
			{
				if (index >= order[i-1]+1 && index <= order[i]) continue;
				if (index <= order[j]) continue;
				three[index] = word[index];
			}
			three[len] = '\0';
		}
		//printf("%s\n", word);
		printf("%s\n", one);
		printf("%s\n", two);
		printf("%s\n", three);
	}
	return 0;
}
