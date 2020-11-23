#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void print_bit(long long int answer){
	while(answer != 0){
		printf("%lld", answer%2);
		answer /= 2;
	}
	printf("\n");
}
*/
int main(){
	char string[100001];
	int i, j, count = 0, N;
	int task_type;
	long long int answer = 0, temp = 0, eight;
	for(i=0; i<8; i++)
		eight = (eight<<1)+1;
	scanf("%d", &task_type);
	if(task_type == 0){
		scanf("%s", string);
		int length = strlen(string);
		for(i=0; i<=length; i++){
			count ++;
			answer = (answer<<8)|string[i];
			if(count == 8){
				printf("%lld\n", answer);
				count = 0;
				answer = 0;
			}
		}
		if(count<8 && count!=0){
			for(i=0; i<(8-count); i++){
				answer = answer << 8;
			}
			printf("%lld\n", answer);
			count = 0;
			answer = 0;
		}
	}
	else if(task_type == 1){
		scanf("%d", &N);
		for(i=0; i<N; i++){
			scanf("%lld", &answer);
			for(j=7; j>=0; j--){
				temp = 0;
				temp = answer & (eight << (8*j));
				temp = temp >> (8*j);
				string[count] = temp;
				count++;
			}
		}
		string[count] = 0;
		printf("%s", string);
	}
	return 0;
}
