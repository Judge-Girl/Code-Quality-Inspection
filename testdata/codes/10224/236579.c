#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int bank[32] = {};
char name[32][100] = {{}};
char instruct[4][10] = {"earns", "spends", "gives", "becomes"};
void regist(int n){
	int money;
	for (int i = 0; i < n; i++){
		scanf("%s%d", name[i], &money);
		bank[i] = money;
	}
	return;
}
int main(){
	int n;	scanf("%d", &n);
	regist(n);
	char s1[32] = {};
	while(scanf("%s", s1) != EOF){
//		printf("ptr1 = %s\n", s1);
		char instruct1[32] = {};
		char s2[32] = {};
		int price;
		int flag = 0;
		int first_person = -1;
		scanf("%s", instruct1);
		char *ptr;

		for (int i = 0; i < n; i++){
			if (!strcmp(s1, name[i])){
				flag = 1;
				first_person = i;
				break;
			}
		}
		if (!flag){
			char s[1000];
			fgets(s, 1000, stdin);
//			printf("invalid s = %s\n", s);
			continue;
		}
		flag = 0;
		for (int i = 0; i < 4; i++){
			ptr = strstr(instruct1, instruct[i]);
			if (ptr != NULL){
//				printf("ptr2 = %s\n", ptr2);
				flag = 1;
				if (i == 2){
					scanf("%s%d", s2, &price);
					for (int j = 0; j < n; j++){
						if (!strcmp(s2, name[j])){
							if (bank[first_person] >= price){
								bank[first_person] -= price;
								bank[j] += price;
							}
							break;
						}
					}
				}
				else{
					scanf("%d", &price);
					if (i == 0)
						bank[first_person] += price;
					else if (i == 1){
						if (bank[first_person] >= price)
							bank[first_person] -= price;
					}
					else
						bank[first_person] = price;
				}
				break;
			}
		}
		if (!flag){
			char s[1000];
			fgets(s, 1000, stdin);
//			printf("invalid s = %s\n", s);
			continue;
		}
	}
	for (int i = 0; i < n; i++){
		printf("%s %d\n", name[i], bank[i]);
	}
	return 0;
}
