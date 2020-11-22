#include <stdio.h>
#define DEBUGINPUT
#define DEBUG
#define MAXSTRLEN 100000
#define MAXN 12500

void Str2Int(char *input){
	unsigned long long output = 0;
	int counter = 0;
	while(*input != '\0'){
		output = output << 8;
		output += *input;
		input++;
		counter++;
		if(counter % 8 == 0){
			printf("%llu\n", output);
			output = 0;
		}
	}
	if(counter % 8 != 0){
		output = output << (8 - (counter % 8)) * 8;
		printf("%llu\n", output);
	} else printf("0\n");
}

void Int2Str(unsigned long long int inputs[], int N){
	char output[MAXSTRLEN];
	int counter = 0;
	for(int n = 0; n < N; n++){
		for(int i = 0; i < 8; i++){
			unsigned long long int temp = inputs[n] << i*8;
			output[counter] = temp >> 56;
			counter++;
		}
	}
	printf("%s\n", output);
	return;
}

int main(){
	int task, N;
	scanf("%d", &task);
	char input[MAXSTRLEN];
	unsigned long long int inputs[MAXN];
	switch(task){
		case 0:
			scanf("%s", &input);
			Str2Int(input);
			break;
		case 1:
			scanf("%d", &N);
			for(int i = 0; i < N; i++){
				scanf("%llu", &inputs[i]);
			}
			Int2Str(inputs, N);
			break;
	}
}

