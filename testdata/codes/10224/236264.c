#include <stdio.h>
#include <string.h>

int main (void)
{
	int N;
	scanf("%d\n", &N);
	char name[32][32];
	int money[32]={0};
	for (int i=0; i<N; i++){
		scanf("%s%d\n", name[i], &money[i]);
		// printf("%d\n", money[i]);
	}
	char command[256];
	while (fgets(command, 256, stdin)!=NULL){
		// printf("%s", command);
		char user[32], DO[32], to[32];
		int amount=0;
		sscanf(command, "%s%s", user, DO);
		int valid=0, A, B;
		for (int i=0; i<N; i++){
			if (!strcmp(user, name[i])) {
				valid=1;
				A=i;
				break;
			}
		}
		if (!valid) {
			// printf("invalid!!\n");
			continue;
		}
		//printf("good\n");
		int type=0;
		for (int i=0; i<strlen(DO); i++){
			if (!strncmp("earns", DO+i, 5)) type=1;
			if (!strncmp("spends", DO+i, 6)) type=2;
			if (!strncmp("becomes", DO+i, 7)) type=3;
			if (!strncmp("gives", DO+i, 5)) type=4;
			if (type) break;
		}
		// printf("%d\n", type);
		if (type==1){
			sscanf(command, "%s%s%d", user, DO, &amount);
			money[A]+=amount;
		}else if (type==2){
			sscanf(command, "%s%s%d", user, DO,&amount);
			if (money[A]<amount) continue;
			else money[A]-=amount;
		}else if (type==3){
			sscanf(command, "%s%s%d",user, DO, &amount);
			money[A]=amount;
		}else if (type==4){
			sscanf(command, "%s%s%s%d", user, DO,to, &amount);
			valid=0;
			for (int i=0; i<N; i++){
				if (!strcmp(to, name[i])) {
					valid=1;
					B=i;
					break;
				}
			}
			if (!valid) {
				// printf("invalid!!\n");
				continue;
			}
			if (money[A]<amount) continue;
			else {
				money[A]-=amount;
				money[B]+=amount;
			}
		}
		// printf("%d\n", amount);
	}
	for (int i=0; i<N; i++){
		printf("%s %d\n", name[i], money[i]);
	}
	return 0;
}
