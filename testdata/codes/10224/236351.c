#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char namelist[32][32];
	int N, balance[32];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%s %d", namelist[i], &balance[i]);
	char cmdname[32], cmd[32];
	int cmdamount;
	while(scanf("%s", cmdname) != EOF)
	{
		int flag = -1;
		for (int i = 0; i < 32; ++i)
		{
			if (strcmp(namelist[i], cmdname) == 0)
			{
				flag = i;
				break;
			}
		}
		if (flag == -1)
			continue;
		scanf("%s", cmd);
		if (strstr(cmd, "earns") != NULL)
		{
			scanf("%d", &cmdamount);
			balance[flag] += cmdamount;
		}
		else if (strstr(cmd, "spends") != NULL)
		{
			scanf("%d", &cmdamount);
			if (balance[flag] >= cmdamount)
				balance[flag] -= cmdamount;
		}
		else if (strstr(cmd, "gives") != NULL)
		{
			char taker[32];
			scanf("%s %d", taker, &cmdamount);
			int flagt = -1;
			for (int i = 0; i < 32; ++i)
			{
				if (strcmp(taker, namelist[i]) == 0)
				{
					flagt = i;
					break;
				}
			}
			if (flagt == -1)
				continue;
			if (balance[flag] >= cmdamount)
			{
				balance[flag] -= cmdamount;
				balance[flagt] += cmdamount;
			}
		}
		else if (strstr(cmd, "becomes") != NULL)
		{
			scanf("%d", &cmdamount);
			balance[flag] = cmdamount;
		}
	}
	for (int i = 0; i < N; ++i)
		printf("%s %d\n", namelist[i], balance[i]);
	return 0;
}
