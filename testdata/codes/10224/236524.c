#include <stdio.h>
#include <string.h>

int main (void)
{
	int N = 0;
	scanf("%d", &N);
	char user[32][100];
	char *ptr[32];
	int user_money[32] = {0};

	for (int i = 0; i < N; i ++){
		scanf("%s", user[i]);
		ptr[i] = user[i];
		scanf("%d", &user_money[i]);
	}

	char target_name1[32];
	char target_name2[32];
	char instruction[32];
	int change = 0;
	char earns[32] = "earns";
	char spends[32] = "spends";
	char gives[32] = "gives";
	char becomes[32] = "becomes";
	int right = 0;

	while (scanf("%s", target_name1) != EOF){
		for (int i = 0; i < N; i ++){
			if (strcmp(target_name1, user[i]) == 0){
				right = 1;
				break;
			}
		}
		if (right == 1){
			scanf("%s", instruction);
			if (strstr(instruction, earns) != NULL){
				scanf("%d", &change);
				for (int i = 0; i < N; i ++){
					if (strcmp(target_name1, user[i]) == 0){
						user_money[i] += change;
						break;
					}
				}
			}

			else if (strstr(instruction, spends) != NULL){
				scanf("%d", &change);
				for (int i = 0; i < N; i ++){
					if (strcmp(target_name1, user[i]) == 0){
						if (user_money[i] >= change){
							user_money[i] -= change;
						}
					break;
					}	
				}
			}

			else if (strstr(instruction, gives) != NULL){
				//printf("in\n");
				scanf("%s", target_name2);
				scanf("%d", &change);
				for (int i = 0; i < N; i ++){
					if (strcmp(target_name1, user[i]) == 0){
						//printf("in\n");
						for (int j = 0; j < N; j ++){
							if (strcmp(target_name2, user[j]) == 0){
								if (user_money[i] >= change){
									//printf("in\n");
									user_money[i] -= change;
									user_money[j] += change;
								
								}
								break;
							}
						}
						break;
					}
				}
			}

			else if (strstr(instruction, becomes) != NULL){
				scanf("%d", &change);
				for (int i = 0; i < N; i ++){
					if (strcmp(target_name1, user[i]) == 0){
						user_money[i] = change;
						break;
					}
				}
			}
			else {
				char nonsence;
				while (scanf("%c", &nonsence) != EOF){
					if (nonsence == '\n'){
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i ++){
		printf("%s ", ptr[i]);
		printf("%d\n", user_money[i]);
	}
		

	return 0;
}
