#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 32

//convert a sting to a positive number
//returns -1 if invalid
int toInt(char string[]){
	int cur = 0;
	for(int i = 0; i < strlen(string); i++){
		if(!isdigit(string[i]))
			return -1;
		cur = cur * 10 + (string[i] - '0');
	}
	return cur;
}

//return 1 if ins matches in string
int match(char string[], char ins[]){
	if(strlen(string) < strlen(ins))
		return 0;

	int correct = 0;
	for(int i = 0; i <= (strlen(string) - strlen(ins)); i++){
		if(strncmp(&string[i], ins, strlen(ins)) == 0){
			correct = 1;
			break;
		}
	}
	return correct;
}

int main()
{
	int total_user_cnt = 0;
	scanf("%d\n", &total_user_cnt);
	int cur_user_cnt = 0;
	char name[total_user_cnt][MAX_LEN];
	int balance[total_user_cnt];

	char command[MAX_LEN * 4] = {'\0'};
	while(fgets(command, MAX_LEN * 4, stdin)){
		char s1[MAX_LEN], s2[MAX_LEN], s3[MAX_LEN], s4[MAX_LEN], s5[MAX_LEN];
		int word_cnt = sscanf(command, "%s %s %s %s %s",s1, s2, s3, s4, s5);

		//user xxx
		if(word_cnt == 2){
			strcpy(name[cur_user_cnt], s1);
			balance[cur_user_cnt] = toInt(s2);
			cur_user_cnt++;
		}

		//user earns   xxx
		//user becomes xxx
		//user spends  xxx
		else if(word_cnt == 3){
			//find the user index
			//continue if invalid
			int idx = -1;
			for(int i = 0; i < cur_user_cnt; i++){
				if(strcmp(name[i], s1) == 0)
					idx = i;
			}
			if(idx == -1)
				continue;
			
			if(match(s2, "earns"))
				balance[idx] += toInt(s3);
			else if(match(s2, "becomes"))
				balance[idx] = toInt(s3);
			else if(match(s2, "spends")){
				int amount = toInt(s3);
				if(balance[idx] < amount)
					continue;
				balance[idx] -= amount;
			}
		}

		//user1 gives user2 xxx
		else if(word_cnt == 4){
			//find the user index
			//continue if invalid
			int idx1 = -1, idx2 = -1;
			for(int i = 0; i < cur_user_cnt; i++){
				if(strcmp(name[i], s1) == 0)
					idx1 = i;
				if(strcmp(name[i], s3) == 0)
					idx2 = i;
			}
			if(idx1 == -1 || idx2 == -1)
			continue;
			
			if(match(s2, "gives")){
				int amount = toInt(s4);
				if(balance[idx1] < amount)
					continue;
				balance[idx1] -= amount;
				balance[idx2] += amount;
			}
		}	
	}

	for(int i = 0; i < cur_user_cnt; i++)
		printf("%s %d\n", name[i], balance[i]);

	return 0;
}
