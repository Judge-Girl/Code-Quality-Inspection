#include <stdio.h>
#include <string.h>
int n, bank[33];
char name[33][33];

void invalid(void){
	for(int i = 0 ; i < 200 ; i++){
		char temp;
		scanf("%c", &temp);
		if(temp == '\n')
			break;
	}
	return;
}

int idSearch(char temp[33]){
	for(int i = 0 ; i < n ; i++)
		if(!strcmp(temp, name[i]))
			return i;
	return -1;
}

int findOrder(char temp[33]){
	int taskSize[4], len = strlen(temp), flag = -1;
	char taskName[4][33];
	taskName[0][0] = 'e';
	taskName[0][1] = 'a';
	taskName[0][2] = 'r';
	taskName[0][3] = 'n';
	taskName[0][4] = 's';
	taskName[1][0] = 's';
	taskName[1][1] = 'p';
	taskName[1][2] = 'e';
	taskName[1][3] = 'n';
	taskName[1][4] = 'd';
	taskName[1][5] = 's';
	taskName[2][0] = 'g';
	taskName[2][1] = 'i';
	taskName[2][2] = 'v';
	taskName[2][3] = 'e';
	taskName[2][4] = 's';
	taskName[3][0] = 'b';
	taskName[3][1] = 'e';
	taskName[3][2] = 'c';
	taskName[3][3] = 'o';
	taskName[3][4] = 'm';
	taskName[3][5] = 'e';
	taskName[3][6] = 's';
	taskSize[0] = 5;
	taskSize[1] = 6;
	taskSize[2] = 5;
	taskSize[3] = 7;
	for(int i = 0 ; i < len && flag == -1; i++){
		switch(temp[i]){
			case 'e':
				if(len - i < taskSize[0])
					break;
				if(!memcmp(&temp[i], taskName[0], taskSize[0]))
					flag = 0;
				break;
			case 's':
				if(len - i < taskSize[1])
					break;
				if(!memcmp(&temp[i], taskName[1], taskSize[1]))
					flag = 1;
				break;
			case 'g':
				if(len - i < taskSize[2])
					break;
				if(!memcmp(&temp[i], taskName[2], taskSize[2]))
					flag = 2;
				break;
			case 'b':
				if(len - i < taskSize[3])
					break;
				if(!memcmp(&temp[i], taskName[3], taskSize[3]))
					flag = 3;
				break;
		}
	}
	return flag;
}

void print(void){
	for(int i = 0 ; i < n ; i++)
		printf("%s %d\n", name[i], bank[i]);
}

int main(void){
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%s%d", name[i], &bank[i]);
	char nameTemp[33], tem[33];
	while(scanf("%s", nameTemp) != EOF){
		//print();
		int Aid, Bid, task, amount;
		char order[33];
		// 1
		Aid = idSearch(nameTemp);
		if(Aid == -1){
			invalid();
			continue;
		}
		// 2
		scanf("%s", order);
		task = findOrder(order);
		if(task == -1){
			invalid();
			continue;
		}
		// 3
		if(task == 2){
			scanf("%s", tem);
			Bid = (idSearch(tem));
			if(Bid == -1){
				invalid();
				continue;
			}
			scanf("%d", &amount);
			if(bank[Aid] < amount){
				invalid();
				continue;
			}
			// gives
			//printf("%s gives %s %d\n", name[Aid], name[Bid], amount);
			bank[Aid] -= amount;
			bank[Bid] += amount;
			//printf("results: %d %d\n", bank[Aid], bank[Bid]);
		}
		else{
			scanf("%d", &amount);
			if(task == 1 && bank[Aid] < amount){
				invalid();
				continue;
			}
			switch(task){
				case 0:
					//printf("%s earns %d\n", name[Aid], amount);
					bank[Aid] += amount;
					//printf("result: %d\n", bank[Aid]);
					break;
				case 1:
					//printf("%s spends %d\n", name[Aid], amount);
					bank[Aid] -= amount;
					//printf("result: %d\n", bank[Aid]);
					break;
				case 3:
					//printf("%s becomes %d\n", name[Aid], amount);
					bank[Aid] = amount;
					//printf("result: %d\n", bank[Aid]);
					break;
			}
		}
		//invalid();
	}
	print();
	return 0;
}

