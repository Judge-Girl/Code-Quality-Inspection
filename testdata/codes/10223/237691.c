#include<stdio.h>
#include<string.h>
#include<ctype.h>
int check(char word)
{
	if (word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u')
		return 1;
	else 
		return 0;
}
int main()
{
	char word[10000];
	int index[10000] = {0};
	int visited[10000] = {0};
	int i, j;
	while (scanf("%s", word) != EOF){
		scanf("%d%d", &i, &j);
		int l = strlen(word);
		int now = 0;
		for (int k = 0; k < l; k++)
		{
			if (check(word[k]) == 1){
				index[now] = k;
				now++;
			}
		}
		index[now] = word[l - 1];
	//	for (int k = 0; k < now; k++)
	//		printf("index %d\n", index[k]);
		for (int k = 0; k < l; k++)
		{
			if (i == 0){
				for (int m = 0; m <= index[0]; m++)
				{
					printf("%c", word[m]);
					visited[m] = 1;
				}
				for (int m = index[0] + 1; m < l; m++)
					printf("+");
				break;
			}
			if (k == index[i - 1])
			{
				printf("+");
				k++;
				while (k <= index[i])
				{
					printf("%c", word[k]);
					visited[k] = 1;
					k++;
				}	
				k--;	
			}
			else printf("+");
		}
		printf("\n");
		for (int k = 0; k < l; k++)
		{
			if (j == 0){
				for (int m = 0; m <= index[0]; m++)
				{
					printf("%c", word[m]);
					visited[m] = 1;
				}
				for (int m = index[0] + 1; m < l; m++)
					printf("+");
				break;
			}
			if (k == index[j - 1])
			{
				printf("+");
				k++;
				while (k <= index[j])
				{
					printf("%c", word[k]);
					visited[k] = 1;
					k++;
				}	
				k--;	
			}
			else printf("+");
		}
		printf("\n");
		for (int k = 0; k < l; k++)
		{
			if (visited[k])
			{
				printf("+");
				visited[k] = 0;
			}
			else
				printf("%c", word[k]);
		}
		printf("\n");
	}
	
	
	return 0;
 } 
