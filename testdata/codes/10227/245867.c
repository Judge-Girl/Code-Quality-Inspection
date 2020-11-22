#include <stdio.h>
#include <string.h>

#define MAXLEN 100001
char string[MAXLEN], *ptr;
int main(void){
	int type;
	unsigned long long num;
	scanf("%d", &type);
	if(!type){
		scanf("%s", string);
		ptr = string;
		while(*ptr != '\0'){
			num = 0;
			for(int i = 0; i < 8; i++){
				num <<= 8;
				num |= (*ptr);
				ptr++;
			}
			printf("%llu\n", num);
		}
		if(strlen(string) % 8 == 0) printf("0\n");
	}	
	else{
		int N, index = 0;
		scanf("%d", &N);
		unsigned long long p = 255;
		for(int i = 0; i < N; i++){
			scanf("%lld", &num);
			for(int j = 0; j < 8; j++){
				string[index] = num >> (8 * (7 - j));
				if(string[index] == '\0') break;
				index++;
			}
		}
		printf("%s\n", string);
	}
	return 0;
}
