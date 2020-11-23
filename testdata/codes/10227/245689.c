#include <stdio.h>
int main(){
	int type;
	scanf("%d",&type);
	if (!type){
		char letter[100000];
		scanf("%s",letter);
		char *start = letter;
		long long int goal = 0;
		int count = 0;
		while(*start != '\0'){
			goal = goal << 8;
			goal = goal | (long long int)*start;
			start++;
			count++;
			if (count == 8){
				printf("%lld\n",goal);
				count = 0;
			}
		}
		if (count != 0){
			goal = goal << (8 * (8 - count));
			printf("%lld\n",goal);
		}
		else{
			printf("0\n");
		}
	}
	else{
		int howmany;
		scanf("%d",&howmany);
		long long int num,one = -1;
		const long long int test = ~(one << 8);
		int flag = 0;
		for (int i = 0; i < howmany; i++){
			scanf("%lld",&num);
			for (int j = 56; j >= 0; j -= 8){
				char goal = (char)((num >> j) & test);
				if (goal == 0)
					break;
				printf("%c",goal);
			}
		}
	}
}
