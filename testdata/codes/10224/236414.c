#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char user[33][33];
int bal[33];
int index = 0;
int N;
char delim[2] = " ";
void setup(char *name, char *value)
{
	strcpy(user[index], name);
	int val = atoi(value);
	bal[index] = val;
	//printf("index: %d, name: %s, balance: %d\n", index, user[index], bal[index]);
	index++;
}

int checkname(char *name)
{
	for (int i = 0; i < N; i++)
	{
		if (strcmp(name, user[i]) == 0)
			return i;
	}
	return -1;
}

void transaction(char *name1, char *action, char *name2, char *value)
{
	int val = atoi(value);
	if (strstr(action, "gives") == NULL)
		return;
	int namea = checkname(name1);
	int nameb = checkname(name2);
	if (namea == -1 || nameb == -1){ 
		//printf("name error");
		return;
	}
	if (bal[namea] < val)
		return;
	//printf("%d", bal[0]);
	bal[namea] -= val;
	bal[nameb] += val;
}

void change(char *name1, char *action, char *value)
{
	int val = atoi(value);
	int name = checkname(name1);
	if (name == -1)
		return;
	
	if (strstr(action, "earns") != NULL){
		bal[name] += val;
		return;
	}
	
	if (strstr(action, "spends") != NULL){
		if (bal[name] >= val)
			bal[name] -= val;
		return;
	}
	
	if (strstr(action, "becomes") != NULL){
		bal[name] = val;
		return;
	}
	return;
}

int main(){
	scanf("%d", &N);
	//printf("%d", N);
	char line[200];
	char ins[4][33];
	int count = 0;
	fgets(line, 200, stdin);//to negate the input of n at the start
	while (fgets(line, 150, stdin) != NULL)
	{
		int inslen = 0;
		char *start = strtok(line, delim);
		while (start != NULL)
		{
			strcpy(ins[inslen], start);
			start = strtok(NULL, delim);
			inslen++;
		}
		if (count < N)
			setup(ins[0], ins[1]);
		if (inslen == 4)
			transaction(ins[0], ins[1], ins[2], ins[3]);
		if (inslen == 3)
			change(ins[0], ins[1], ins[2]);
		count++;
	}
	for (int i = 0; i < N; i++)
		printf("%s %d\n", user[i], bal[i]);
}
