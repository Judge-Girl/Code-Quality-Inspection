#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char name[64][64];
int money[64];
int main(){
	char str[64], cur[64], names[64];
	int name_cnt = 0, cur_cnt, N, now, money_now, now2;
	scanf("%d", &N);
	while((scanf("%s", str)) != EOF){
		now = -1;
		now2 = -1;
		if(isalpha(str[0])){
			for(int i = 0; i < name_cnt; i++){
				if(strcmp(str, name[i]) == 0){
					now = i;
					break;
				}
			}
			strcpy(names, str);
			scanf("%s", str);
			if(now == -1 && !isdigit(str[0])){
				while(1){
					scanf("%s", str);
					if(isdigit(str[0])) break;
				}
				continue;
			}
			else if(now == -1){
				strcpy(name[name_cnt], names);
				money[name_cnt] = atoi(str);
				name_cnt++;
				continue;
			}
			else{
				if(strstr(str, "spends") != NULL){
					scanf("%s", str);
					if(!isdigit(str[0])) continue;
					money_now = atoi(str);
					if(money[now] - money_now >= 0) money[now] -= money_now;
				}
				else if(strstr(str, "earns") != NULL){
					scanf("%s", str);
					if(!isdigit(str[0])) continue;
					money_now = atoi(str);
					money[now] += money_now;
				}
				else if(strstr(str, "gives") != NULL){
					scanf("%s", str);
					if(!isalpha(str[0])) continue;
					for(int i = 0; i < name_cnt; i++){
						if(strcmp(str, name[i]) == 0){
							now2 = i;
							break;
						}
					}
					if(now2 == -1){
						scanf("%s", str);
						continue;
					}
					scanf("%s", str);
					if(!isdigit(str[0])) continue;
					money_now = atoi(str);
					if(money[now] >= money_now){
						money[now] -= money_now;
						money[now2] += money_now;
					}
				}
				else if(strstr(str, "becomes") != NULL){
					scanf("%s", str);
					if(!isdigit(str[0])) continue;
					money_now = atoi(str);
					money[now] = money_now;
				}
				else{
					while(1){
						scanf("%s", str);
						if(isdigit(str[0])) break;
					}
				}
			}
		}
	}
	for(int i = 0; i < name_cnt; i++){
		printf("%s ", name[i]);
		printf((i == name_cnt-1)? "%d" : "%d\n", money[i]);
	}
}
