#include <stdio.h>
#include <string.h>
#define MAXN 32
#define invalid -1
enum {EARN = 0, SPEND, GIVE, BECOME};


int n;
char name[32][35];
long long money[32];
char buffer[200];

int which_cmd(char cmd[])
{
	if (strstr(cmd, "earns") != NULL)
		return EARN;
	else if (strstr(cmd, "spends") != NULL)
		return SPEND;
	else if (strstr(cmd, "gives") != NULL)
		return GIVE;
	else if (strstr(cmd, "becomes") != NULL)
		return BECOME;

	return invalid;
}

int find_user (char user[])
{
	int user_id;
	int i;
	
	for (i = 0; i < n; i++)
		if (!strcmp(user, name[i])) {
			user_id = i;
			break;
		}

	if (i == n)
		return invalid;
		
	return user_id;
}

void eatline(void)
{
	char c;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			return;
}

void instruction(char user[], char cmd[])
{
	int instruct = which_cmd(cmd);
	int user_id = find_user(user), user2_id;
	long long amount;
	char user_2[35];
	
	if (user_id == invalid || instruct == invalid) {
		eatline();
		//fgets(buffer, sizeof(buffer), stdin);
		return;
	}
	
	switch (instruct) {
		case EARN:
			scanf("%lld", &amount);
			money[user_id] += amount;
			break;
		case SPEND:
			scanf("%lld", &amount);
			if (money[user_id] < amount)
				break;
			money[user_id] -= amount;
			break;
		case GIVE:
			scanf("%s%lld", user_2, &amount);
			user2_id = find_user(user_2);
			if (user2_id == invalid)
				break;
			if (money[user_id] < amount)
				break;
			money[user_id] -= amount;
			money[user2_id] += amount;
			break;
		case BECOME:
			scanf("%lld", &amount);
			money[user_id] = amount;
			break;
	}
eatline();
	//fgets(buffer, sizeof(buffer), stdin);
	return;
}

int main(void)
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%s%lld", name[i], &money[i]);
	/*	
	for (int i = 0; i < n; i++)
		printf("%s %d\n", name[i], money[i]);
*/
	char user[35], cmd[35];
	
	while (scanf("%s%s", user, cmd) > 0)
		instruction(user, cmd);
		
	for (int i = 0; i < n; i++)
		printf("%s %lld\n", name[i], money[i]);	
		
	return 0;
}

