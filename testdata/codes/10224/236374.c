#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	char str1[64],str2[64];
	int n,i;
	scanf("%d",&n);
	int money[n];
	char name[n][64];
	for(i = 0; i < n; i ++)
	{
		scanf("%s%s",str1,str2);
		money[i] = atoi(str2);
		strcpy(name[i],str1);
	}
	char instr[256] = {'\0'};
	while(gets(instr) != NULL)
	{
		int j = 0;
		char subinstr[4][64] = {{'\0'}};
		char cut[] = " ";
		char *start = instr;
		start = strtok(start,cut);
		while(start != NULL)
		{
			strcpy(subinstr[j],start);
			j ++;
			start = strtok(NULL,cut);
		}
		int user1 = -1;
		for(i = 0; i < n; i ++)
		{
			if(strcmp(name[i],subinstr[0]) == 0)
			{
				user1 = i;
				break;
			}
		}
		if(user1 == -1)
			continue;
		char e[] = "earns",s[] = "spends",g[] = "gives",b[] = "becomes";
		if(strstr(subinstr[1],e) != NULL)
		{
			int earn = atoi(subinstr[2]);
			money[user1] += earn;
		}
		if(strstr(subinstr[1],s) != NULL)
		{
			int spend = atoi(subinstr[2]);
			if(money[user1] >= spend)
				money[user1] -= spend;
		}
		if(strstr(subinstr[1],g) != NULL)
		{
			int user2 = -1;
			for(i = 0; i < n; i ++)
			{
				if(strcmp(name[i],subinstr[2]) == 0)
				{
					user2 = i;
					break;
				}
			}
			if(user2 == -1)
				continue;
			int give = atoi(subinstr[3]);
			if(money[user1] >= give)
			{
				money[user1] -= give;
				money[user2] += give;
			}
		}
		if(strstr(subinstr[1],b) != NULL)
		{
			money[user1] = atoi(subinstr[2]);
		}
	}
	for(i = 0; i < n; i ++)
		printf("%s %d\n",name[i],money[i]);
}
