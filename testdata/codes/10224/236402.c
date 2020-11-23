#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int n;
	char name[35][128] = {{}}, ins[256] = {}, del[2], empty[256] = {};
	char table[5][32] = {"earns", "spends", "gives", "becomes"};
	del[0] = ' ';
	del[1] = '\0';
	int money[32] = {};
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%s%d", name[i], &money[i]);
	while(gets(ins)){
		int cnt = 0;
		char temp[5][35] = {}, *tok = ins;
		tok = strtok(ins, del);
		while(tok != NULL){
			strcpy(temp[cnt ++], tok);
			tok = strtok(NULL, del);
		}
		if(cnt == 3){
			int mon = atoi(temp[2]);
			int a = -1;
			for(int i = 0; i < n; i ++){
				if(strcmp(temp[0], name[i]) == 0){
					a = i;
					break;
				}
			}
			if(a == -1)
				continue;
			char *ptr;
			int b;
			for(int i = 0; i < 4; i ++){
				ptr = strstr(temp[1], table[i]);
				if(ptr != NULL){
					b = i;
					break;
				}
			}
			if(ptr == NULL)
				continue;
			if(b == 0)
				money[a] += mon;
			else if(b == 1){
				if(money[a] >= mon)
					money[a] -= mon;
			}
			else if(b == 3)
				money[a] = mon;
		}
		if(cnt == 4){
			int mon = atoi(temp[3]);
			int a = -1, b = -1;
			for(int i = 0; i < n; i ++){
				if(strcmp(temp[0], name[i]) == 0)
					a = i;
				if(strcmp(temp[2], name[i]) == 0)
					b = i;
			}
			if(a == -1 || b == -1)
				continue;
			char *ptr;
			ptr = strstr(temp[1], table[2]);
			if(ptr == NULL)
				continue;
			if(money[a] >= mon){
				money[a] -= mon;
				money[b] += mon;
			}
		}
		strcpy(ins, empty);
	}
	for(int i = 0; i < n; i ++){
		printf("%s %d\n", name[i], money[i]);
	}
	return 0;
}

